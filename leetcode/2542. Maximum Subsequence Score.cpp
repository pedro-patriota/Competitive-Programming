#include <bits/stdc++.h>
using namespace std;

/*
nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
-> 12
1 3 2 
2

nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
-> 30
3
10

1
Calculate all the subsequences and do brute force
time: O(2^n)
complexity: O(N)

2

1 3 3 2
      ^

2 1 3 4
      ^

4 3 2 1 nums2
    ^
2 3 1 3 nums1

*/

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long long sz = nums1.size(), ans = 0, curr_sum = 0, worst_val;
    vector<pair<int, int>> merged (sz);

    for (int i = 0; i < sz; i++) {
        merged[i] = {nums2[i], nums1[i]};
    }
    sort(merged.begin(), merged.end(), greater<pair<int, int>>());

    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    for (auto [curr_min, new_val] : merged) {
        if (min_heap.size() == k) {
            worst_val = min_heap.top();
            min_heap.pop();
            curr_sum -= worst_val;
        }
        min_heap.push(new_val);
        curr_sum += new_val;

        ans = max(ans, curr_sum*curr_min);
    }
    return ans;
}

int main () {

}