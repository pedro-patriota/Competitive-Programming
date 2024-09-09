#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Input: nums = [5], k = 1
Output: 5.00000

nums < 1e5
-1e4 < nums[i] < 1e4

1, 2, 3, 4, 5 k = 2
4.5

4 5 9 1 12 k = 6 
-1

1 2 3 k = 0

8 7 2 9 k = 1
9

-1 3 -4 10 k = 2
3

1 Approach

k = 4
max_sum = 51
sum = 2 - 1 + 50 = 51 - 12 + 3 = 42

1,12,-5,-6,50,3
      ^       ^

-> max_sum/k

time: O(N)
space: O(1)

*/

double findMaxAverage(vector<int>& nums, int k) {
    int sz = nums.size(), max_sum = 0, sum = 0;
    if (sz < k  || k <= 0) {
        return -1;
    }
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    max_sum = sum;
    for (int right = k; right < sz; right++) {
        int left = right - k + 1;
        sum += nums[right] - nums[left - 1];
        max_sum = max(sum, max_sum);
    }

    return (double) max_sum/k;
}

int main () {
    vector<int> nums = {1,12,-5,-6,50,3};

    cout << findMaxAverage(nums, 4) << endl; // 12.75

    nums = {5};
    cout << findMaxAverage(nums, 1) << endl; // 5

    nums = {1, 2, 3, 4, 5};
    cout << findMaxAverage(nums, 2) << endl; // 4.5

    nums = {1, 2, 3, 4, 5};
    cout << findMaxAverage(nums, 10) << endl; // -1

    nums = {1, 2, 3, 4, 5};
    cout << findMaxAverage(nums, 0) << endl; // -1

    nums = {1, 2, 3, 4, 5};
    cout << findMaxAverage(nums, 1) << endl; // 5

    nums = {-1, 3, -4, 10};
    cout << findMaxAverage(nums, 2) << endl; // 3

}