#include <bits/stdc++.h>
using namespace std;

/*
[1,4], [3, 9], [4, 11], [9, 10] -> 2
-> [1, 4], [3, 9],  [9, 10], [4, 11]

[1, 7], [2, 2], [3, 3], [4, 4], [5, 5] -> 2
-> {2,2}, {2, 3}, {3, 3}, {4, 4}, {5, 5}, {1, 7}


1. sort by then end time
2. use a ordered set to store the end time of each room
3. make a lower bound search for the current start time
    3.1 if lower bound in the begining (no room ended yet), insert end time
    3.2 otherwise substitute the closest end time room by my current room
4. return set size

Time: O(NlogN)
Space: O(N)
*/

int findMaxRooms(vector<vector<int>> input) {
    int cnt = 0;
    int sz = input.size();
    for (int i = 0; i < sz; i++) {
        input[i] = {input[i][1], input[i][0]};
    }
    set<int> end_rooms;
    sort(input.begin(), input.end()); // 0 -> end, 1-> start
    end_rooms.insert(input[0][0]);
    for (int i = 1; i < sz; i++) {
        int start = input[i][1];
        int end = input[i][0];

        auto it = end_rooms.lower_bound(start);
        if (it == end_rooms.begin() && start < *it) {
            end_rooms.insert(end);
        } else {
            if (it == end_rooms.end()) {
                it--;
            }
            end_rooms.erase(it);
            end_rooms.insert(end);
        }
    }

    return end_rooms.size();
}

int main() {
    cout << findMaxRooms({{2,2}, {2, 3}, {5, 5}, {1, 7}, {3, 3}, {4, 4}}) << endl; // 2
    cout << findMaxRooms({{1,4}, {3, 9}, {4, 11}, {9, 10}}) << endl; // 2
    cout << findMaxRooms({{0,30}, {5, 10}, {15, 20}}) << endl; // 2
    cout << findMaxRooms({{7,10}, {2, 4}}) << endl; // 1
}