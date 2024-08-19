#include <bits/stdc++.h>
using namespace std;

void findCombinationsSum(vector<vector<int>>& comb, vector<int>& candidates, vector<int>& curr, int target, int curr_sum) {
    if (curr_sum == target) {
        comb.push_back(curr);
    } else if (curr_sum < target) {
        for (auto value : candidates) {
            curr.push_back(value);
            curr_sum += value;
            findCombinationsSum(comb, candidates, curr, target, curr_sum);
            curr_sum -= value;
            curr.pop_back();
        }
    }
} 


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    findCombinationsSum(ans, candidates, curr, target, 0);
    return ans;
}
