#include <bits/stdc++.h>
using namespace std;

/*
1 2 3 3 4 5 6 6 6 6 6
k               ^
j                     ^
*/

int removeDuplicates(vector<int>& nums) {
    int k = 1, j = 1, sz = nums.size(), rep = 1;
    while (j < sz) {
        if (nums[j] == nums[k - 1]) {
            rep++;
        } else {
            rep = 1;
        }
        if (rep > 2) {
            while (j < sz && nums[j] == nums[k - 1]) {
                j++;
            }
            rep = 1;
            if (j >= sz) {
                break;
            }
        }
        nums[k] = nums[j];
        j++;
        k++;
    }
    return k;
}