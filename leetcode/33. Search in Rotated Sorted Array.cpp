#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1

1, 2, 3, 4  target = 2
1

[] target = 2
-1

-4 -8 -1 -2 -3  target = -3
4

No duplicates

[4,5,6,7,0,1,2]
         ^
[0, 1, 2, 4, 5, 6, 7]

time: O(n)
space: O(n) -> O(1)

[4, 5, 6, 7, 8, 0, 1, 2, 3]
                   ^
                ^
                         ^

compare using m
check the border pointer 
if border == l
    if value l < value m && value l > target
        go to right
    else
        go to left
else if border == r 
    if value m  < value r && value r <= target
        go to left
    else 
        go to right

4 5 6 7 0
      ^ 
    ^   ^

*/

// int searchRotatedArray(vector<int>& arr, int target) {
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] == target) {
//             return i;
//         }
//     }
//     return -1;
// }

int searchRotatedArray (vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1, m;

    while (l < r) {
        m = (l + r)/2;
        if (arr[m] == target) {
            return m;
        }
        if (target < arr[m]) {
            if (arr[l] < arr[m] && arr[l] > target) {
                l = m + 1;
                // go right
            } else {
                r = m;
                // got left
            }
        } else {
            if (arr[r] > arr[m] && arr[r] < target) {
                // go left
                r = m;
            } else {
                l = m + 1;
                // got right
            }
        }
    }
    if (arr[l] == target) {
        return l;
    } else {
        return -1;
    }
}

int main () {
    vector<int> arr = {4,5,6,7,0,1,2};
    cout << searchRotatedArray(arr, 6) << endl;
}