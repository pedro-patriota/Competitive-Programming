#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int sz = nums.size();
    vector<int> sufix (sz + 1, 1);
    for (int i = sz - 1; i >= 0; i--) {
        sufix[i] = nums[i] * sufix[i + 1];
    }
    int prefix = 1;
    for (int i = 0; i < sz; i++) {
        nums[i] = prefix*sufix[i+1];
        prefix *= nums[i];
    }
    return nums;
}
