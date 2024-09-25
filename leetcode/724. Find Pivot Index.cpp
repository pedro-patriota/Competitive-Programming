#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int left_sum = 0, sum, sz = nums.size();
    sum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < sz; i++) {
        if (left_sum == sum - nums[i]) {
            return i;
        }
        left_sum += nums[i];
        sum -= nums[i];
    }
    return -1;
}

int main () {

}