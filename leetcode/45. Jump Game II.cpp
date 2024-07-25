#include <bits/stdc++.h>
using namespace std;

/*
s
4 - 2
3 - 3


cnt = 
range = 3
[2,3,1,1,4]
         ^

*/

int jump(vector<int>& nums) {
    int act_range, max_range, dist;
    dist = act_range = max_range = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > act_range) {
            dist++;
            act_range = max_range;
        }

        max_range = max(nums[i] + i, max_range);
    }
    return dist;
}
