#include <bits/stdc++.h>
#define ii tuple<int, int, int>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int sz1 = nums1.size(), sz2 = nums2.size();  
    vector<vector<int>> ans (k);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < sz1; i++) {
        pq.push({nums1[i] + nums2[0], i, 0});
    } 
    for (int cnt = 0; cnt < k; cnt++) {
        auto [sum, i, j] = pq.top();
        ans[cnt] = {nums1[i], nums2[j]};
        pq.pop();

        if (j + 1 < sz2) {
            pq.push({nums1[i] + nums2[j+1], i, j+1});
        }
    }  
    return ans;
}
