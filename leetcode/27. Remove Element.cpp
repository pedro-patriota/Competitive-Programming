#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j, i = 0;
    bool out_of_bound = false;

    for (j = 0; j < nums.size(); j++) {
        while (nums[i] == val) {
            i++;
            if (i == nums.size()) {
                out_of_bound = true;
                break;
            }
        }
        if (out_of_bound) {
            break;
        }
        swap(nums[i], nums[j]);
    }

    return j;

}
/* 
    0,1,3,0,4,2,2,2   val = 2
              j
                   i

    3 3 2 2     val = 2
        j
           i

    2 2 2  val  = 2
    j 
          i


*/

int main()
{
    
}