#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,2,3,4,5]
Output: true
1 2 3 

Input: nums = [5,4,3,2,1]
Output: false

Input: nums = [2,1,5,0,4,6]
Output: true
1 4 6
2 4 6 

[]
Output: false

[1, 2]
Output: false

[-1, 10, 2, -3, -5]
false

[1, 5, 2]
false

[1, 1, 1]
false

1 Approach
time: O(n^3)
space: O(1)

2 Approach
Check for min and max from a certain index
time: O(N)
space: O(N)

*/
bool increasingTriplet(vector<int>& nums) {
    int sz = nums.size(), mn;
    vector<int> mx (sz);
    mx[sz-1] = nums[sz-1];
    for (int i = sz - 2; i >= 0; i--) {
        mx[i] = max(nums[i], mx[i + 1]);
    }
    mn = nums[0];
    for (int i = 1; i < sz -1; i++) {
        if (nums[i] > mn && nums[i] < mx[i + 1]) {
            return true;
        }
        mn = min(mn, nums[i]);
    }
    return false;
}
// bool increasingTriplet(vector<int>& nums) {
//     int sz = nums.size();

//     for (int i = 0; i < sz; i++) {
//         for (int j = i + 1; j < sz; j++) {  
//             for (int m = j + 1; m < sz; m++) {
//                 if (nums[i] < nums[j] && nums[j] < nums[m]) {
//                     return true;
//                 }
//             }
//         }
//     }

//     return false;
// }

int main () {
    vector<int> nums = {2,1,2,0,4};
    cout << increasingTriplet(nums) << endl; // 1

    nums = {1,2,3,4,5};
    cout << increasingTriplet(nums) << endl; // 1
    
    nums = {6, 7, 1, 3};
    cout << increasingTriplet(nums) << endl; // 0

    nums = {1,2};
    cout << increasingTriplet(nums) << endl; // 0

    nums = {2,1,5,0,4,6};
    cout << increasingTriplet(nums) << endl; // 1
    
    nums = {5,4,3,2,1};
    cout << increasingTriplet(nums) << endl; // 0

    nums = {-1, 10, 2, -3, -5};
    cout << increasingTriplet(nums) << endl; // 0
}