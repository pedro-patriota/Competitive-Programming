#include <bits/stdc++.h>
using namespace std;

/*
(8.5, 9.5), (11, 11.25), (9, 11), (11.5, 13), (10, 10.75), (8, 9)
4 (The following meetings can occur in the given order: (8, 9), (10, 10.75), (11, 11.25), 11.5, 13))

(8, 9), (9, 10)
2

[]
0

(1,1), (2,2), (3,3), (4,4)
4

(1,5) (1,2), (3, 5), (5, 6)
3

(3, 5), (2, 5)  (1, 3)
2

                                                          ^
cnt = 4
curr = (11.5, 11.13)

(1,5) (1,2), (3, 5), (5, 6)
(1,2) (1,5) (3, 5) (5, 6)
                    ^

cnt = 2
curr = (3, 5)

time complexity: O(NlogN)
space complexity: O(1)

(8.5, 9.5), (11, 11.25), (9, 11), (11.5, 13), (10, 10.75), (8, 9)
-> (8, 9) (8.5, 9.5) (10, 10.75) (9, 11), (11, 11.25) (11.5, 13)
*/

int findMaxMeetings(vector<pair<double, double>>& arr) {
    int sz = arr.size();
    if (sz == 0) {
        return 0;
    }
    for (int i = 0; i < sz; i ++) {
        double temp = arr[i].first;
        arr[i].first = arr[i].second;
        arr[i].second = temp;
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    auto curr = arr[0];
    for (int i = 1; i < sz; i++) {
        auto next = arr[i];
        double next_begin = next.second;
        double curr_end = curr.first;

        if (next_begin >= curr_end) {
            cnt++;
            curr = next;
        }
    }
    return cnt;
}


int main () {
    vector<pair<double, double>> input = {
        {8.5, 9.5}, {11, 11.25}, {9, 11}, {11.5, 13}, {10, 10.75}, {8, 9}
    };
    cout << "Expected: 4 / Got: " << findMaxMeetings(input) << endl;

    input = {{8, 9}, {9, 10}};
    cout << "Expected: 2 / Got: " << findMaxMeetings(input) << endl;

    input = {{1,1}, {2,2}, {3,3}, {4,4}};
    cout << "Expected: 4 / Got: " << findMaxMeetings(input) << endl;

    input = {{1,5}, {1,2}, {3, 5}, {5, 6}};
    cout << "Expected: 3 / Got: " << findMaxMeetings(input) << endl;

    input = {{3, 5}, {2, 5}, {1, 3}};
    cout << "Expected: 2 / Got: " << findMaxMeetings(input) << endl;

}