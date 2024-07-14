#include <bits/stdc++.h>
using namespace std;
/*

Input: [(8.5, 9.5), (11, 11.25), (9, 11), (11.5, 13), (10, 10.75), (8, 9)]
Output: 4 (The following meetings can occur in the given order: (8, 9), (10, 10.75), (11, 11.25), 11.5, 13))
8-9
    10- 10.75
                11-11.25
                            11.5-13
input: []
output: 0


input: [(1,8), (1, 2) , (2, 3), (3, 5)]
output: 3

input: [(1,2), (2, 3)]
output: 2

input: [(1,2), (1, 2)]
output: 1

input: [(-1, 2)]  X


input : [(1, 2), (2, 3), (3, 4)]

(8.5, 9.5), (11, 11.25), (9, 11), (11.5, 13), (10, 10.75), (8, 9)
-> (8, 9), (8.5, 9.5), (9,11), (10, 10.75) (11, 11.25) (11.5, 13)
                                                           ^
------- ----------
    --------- ------------

double cnt = 1 -> 2 -> 3 -> 4
pair p = (11.5, 13)


(1,8), (1, 2) , (2, 3), (3, 5)
(1, 2), (1, 8), (2, 3), (3, 5)
                                ^

double cnt = 1 -> 2 -> 3
pair p = (3, 5)

*/

/*
Time: O(NlogN)
Space: O(1)
 */
    

int findMaxiumTimeSpaces(vector<pair<double, double>>& input) {
    sort(input.begin(), input.end());
    if (input.size() == 0) {
        return 0;
    }
    pair<double, double> p = input[0];
    int cnt = 1;
    cout << p.first << " " << p.second << endl;
    for (double i = 1; i < input.size(); i++) {
        pair<double, double> p_input = input[i];
        if (p.second > p_input.first) {
            if (p_input.second < p.second) {
                p = p_input;
            }
        } else {
            cnt++;
            p = p_input;

        }
        cout << p.first << " " << p.second << endl;
      
    }
    return cnt;
}

int main() {
    vector<pair<double, double>> input = {{8.5, 9.5}, {11, 11.25}, {9, 11}, {11.5, 13}, {10, 10.75}, {8, 9}};
    cout << findMaxiumTimeSpaces(input);

}