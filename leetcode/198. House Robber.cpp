#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1) {
        return nums[0];
    }
    vector<int> dp (sz);
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < sz; i++) {
        dp[i] = max(nums[i] + dp[i -2], dp[i - 1]);
    }

    return dp[sz - 1];
}
