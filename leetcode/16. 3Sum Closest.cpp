#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 1e9, sz = nums.size(), ans_sum, l, r, curr_sum;

    for (int i = 0; i < sz - 2; i++) {
        l = i + 1;
        r = sz -1;

        while (l < r) {
            curr_sum = nums[i] + nums[l] + nums[r];
            if (curr_sum == target) {
                return curr_sum;
            }
            if (abs(target - curr_sum) < ans) {
                ans = abs(target-curr_sum);
                ans_sum = curr_sum;
            }
            if (curr_sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return ans_sum;
}


int main () {
    vector<int> nums = {-4, -1, 1, 2};
    cout << threeSumClosest({nums}, 1);
}