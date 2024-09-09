#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int cnt, mx, prev, sz = nums.size();   
    cnt = mx = prev = 0;

    bool has_zero = false;

    for (int i = 0; i < sz; i++) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            has_zero = true;
            mx = max(cnt, mx);
            if (prev != 0) {
                mx = max(cnt+prev, mx);
            }
            if (i + 1 < sz && nums[i + 1] == 1) {
                prev = cnt;
            } 
            cnt = 0;
        }
    }
    mx = max(cnt, mx);
    if (prev != 0) {
        mx = max(cnt+prev, mx);
    }
    mx -= !has_zero;
    
    return mx;

}

int main () {

}