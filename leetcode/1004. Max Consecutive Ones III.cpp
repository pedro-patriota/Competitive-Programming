#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int mx, left, right, sz = nums.size(), cnt;
    mx = left = right = cnt = 0;

    for (; right < sz; right ++) {
        cnt++;
        if (nums[right] == 0) {
            k--;
            while (k == 0) {
                if (nums[left] == 0) {
                    k++;
                }
                cnt--;
                left++;
            }
        }
        mx = max(cnt, mx);
    }
    return mx;
}

int main () {

}