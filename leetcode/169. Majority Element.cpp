#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

const int INF = -1e9 -1e4;

int majorityElement(vector<int>& nums) {
    int rep = 1, best_rep = 1, best_v = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            rep++;
            if (rep > best_rep) {
                best_rep = rep;
                best_v = nums[i];
            }
        }else {
            rep = 1;
        }
    }
    
    return best_v;
}

int main()
{
    
    return 0;
}