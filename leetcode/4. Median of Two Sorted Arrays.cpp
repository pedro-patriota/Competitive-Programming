#include <bits/stdc++.h>
using namespace std;

/*
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


[1, 4, 9] [2, 3, 7, 10]
1 2 3 4 7 9 10
-> 4

[] [1, 2, 2, 3]
-> 2

[-1, 5] [-4, 0]
-4 -1 0 5
-> -0.5

[1] [0]
->1

[1] [5]
-> 3

1 7 9
  ^
2 3 4 10
  ^

1, 4, 9
   ^


2, 3, 7, 10
    ^

*/

double medianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged_array;
    double ans;

    int i = 0, j = 0, sz1 = arr1.size(), sz2 = arr2.size();
    while (true) {
        if (i == sz1 && j == sz2) {
            break;
        } else if (i == sz1) {
            merged_array.push_back(arr2[j]);
            j++;
        } else if (j == sz2) {
            merged_array.push_back(arr1[i]);
            i++;
        } else {
            if (arr1[i] < arr2[j]) {
                merged_array.push_back(arr1[i]);
                i++;
            } else {
                merged_array.push_back(arr2[j]);
                j++;
            }
        }
    }
    ans = merged_array[(sz1 + sz2)/2];
    if (merged_array.size()%2 == 0) {
        ans += merged_array[((sz1 + sz2)/2)  - 1];
        ans /= (double) 2;
    }
    return ans;

}

int main () {
    vector<int> arr1 = {1, 4, 9};
    vector<int> arr2 = {2, 3, 7, 10};
    cout << "Expected: 4 / Got " << medianSortedArrays(arr1, arr2) << endl;

    arr1 = {1,3};
    arr2 = {2};
    cout << "Expected: 2 / Got " << medianSortedArrays(arr1, arr2) << endl;

    arr1 = {1,2};
    arr2 = {3, 4};
    cout << "Expected: 2.5 / Got " << medianSortedArrays(arr1, arr2) << endl;

    arr1 = {};
    arr2 = {1, 2, 2, 3};
    cout << "Expected: 2 / Got " << medianSortedArrays(arr1, arr2) << endl;

    arr1 = {-1, 5};
    arr2 = {-4, 0};
    cout << "Expected: -0.5 / Got " << medianSortedArrays(arr1, arr2) << endl;
}