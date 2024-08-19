#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    int sz = nums.size();
    vector<vector<int>> ans;
    vector<int> pos(sz);
    for (int i = 0; i < sz; i++) {
        pos[i] = i;
    }
    ans.push_back(nums);
    while(next_permutation(pos.begin(), pos.end())) {
        vector<int> perm(sz);
        for (int i = 0; i < sz; i++) {
            perm[i] = nums[pos[i]];
        }
        ans.push_back(perm);
    }
    return ans;
}
