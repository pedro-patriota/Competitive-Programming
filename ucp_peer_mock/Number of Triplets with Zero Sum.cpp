#include <bits/stdc++.h>
using namespace std;

/*
8, 2, 3, 5, -2, 1, -1, 3
=> 2

(3, -2, -1) 
(-2, -1, 3)

5, 0, -5, -2, 4, 1, -3, 6
3
(5, 0, -5)
(5, -2, 3)
(-5, 4, 1)

0 0 0 
=> 1

-2 0 1 5 
=> 0

[]
=> 0

-2 0 4
=> 0

-2 -2 4
=> 1

4, -2 -2 -2 
=> 3

Time: O(n^2)
Space: O(n)

*/

int findNumberTriplets (vector<int>& arr) {
    int sz = arr.size();
    if (sz < 3) {
        return 0;
    }
    unordered_map<int, int> last_seen;
    for (int i = 0; i < sz; i ++) {
        last_seen[arr[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            int v1 = arr[i];
            int v2 = arr[j];
            int target = -(v1 + v2);
            if (last_seen.count(target)) {
                if (last_seen[target] > i && last_seen[target] > j) {
                    ans++;
                }
            }
        }
    }
    return ans;
}


int main () {
    vector<int> input = {8, 2, 3, 5, -2, 1, -1, 3};
    cout << "Expected: 2 " << findNumberTriplets(input) << endl;

    input = {5, 0, -5, -2, 4, 1, -3, 6};
    cout << "Expected: 3 " << findNumberTriplets(input) << endl;

    input = {0, 0, 0};
    cout << "Expected: 1 " << findNumberTriplets(input) << endl;

    input = {-2, 0, 1, 5};
    cout << "Expected: 0 " << findNumberTriplets(input) << endl;

    input = {-2, 0, 4};
    cout << "Expected: 0 " << findNumberTriplets(input) << endl;

    input = {-2, -2, -2, 4};
    cout << "Expected: 3 " << findNumberTriplets(input) << endl;

}