#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, bool> is_intercection1;
    unordered_map<int, bool> is_intercection2;
    for (auto v : nums1) {
        is_intercection1[v] = false;
    }
    for (auto v : nums2) {
        is_intercection2[v] = false;
    }
    for (auto [v, has_intercect] : is_intercection1) {
        if (is_intercection2.count(v)) {
            is_intercection2[v] = true;
            has_intercect = true;
        }
    }

    vector<vector<int>> ans = {{}, {}};
    for (auto [v, has_intercect] : is_intercection1) {
        if (not has_intercect) {
            ans[0].push_back(v);
        }
    }
    for (auto [v, has_intercect] : is_intercection2) {
        if (not has_intercect) {
            ans[1].push_back(v);
        }
    }

    return ans;
}


int main() {

}