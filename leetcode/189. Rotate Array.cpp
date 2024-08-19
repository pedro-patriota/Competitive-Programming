#include <bits/stdc++.h>
using namespace std;

/*
k = 0 -> nums
k >= size of array -> k mod size of array

1
counter = 7
[5,6,7,1,2,3,4] k = 3
 ^
if counter = size of array -> return the recursion 

[1, 2, 3, 4,5 ] k = 3
      ^
next = 2   
val = 2
i = 0
counter = 3

*/


void rotate(vector<int>& nums, int k) {
    int counter = 0, sz = nums.size(), i = 0, val;
    k = k%sz;
    if (k == 0) {
        return;
    }
    for (int init = 0; init < k; init++) {
        val = nums[init];
        i = init;
        while (true) {
            int next = (i + k)%sz, prev = nums[next];
            nums[next] = val;
            val = prev;
            i = next;
            counter++;
            
            if (next == init) {
                break;
            }
        }
        if (counter == sz) break;
    }

}
