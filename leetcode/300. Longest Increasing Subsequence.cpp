#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int sz = nums.size();
    vector<int> dp (sz, 1);
    for (int i = sz - 2; i >= 0; i--) {
        for (int j = i + 1; j < sz; j++) {
            if (nums[i] < nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            } 
        }
    }
    int mx = *max_element(dp.begin(), dp.end());
    return mx;
}
