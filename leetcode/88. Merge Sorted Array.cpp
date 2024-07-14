#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*
    p, z
        j
    1 2 2 3 5 6  
      p

    2 5 6
   z 

    p ? p >= m

    4 5 5 6 0 0 0  
                p       

    2 3 4 7
          z

    j
    1 3 3 4 4 5 6 6 
   p
    1 4 5 
    z


    b = INF 
    */

   if (n == 0) {
        return;
   }
   if (m == 0) {
        nums1 = nums2;
        return;
   }
   
   int p = m - 1, z = n -1, j = m + n - 1;

    while (p >= 0 && z >= 0) {
        if (nums1[p] > nums2[z]) {
            nums1[j] = nums1[p];
            p--;
        }else {
            nums1[j] = nums2[z];
            z--;
        }
        j--;
    }
    while (p >= 0) {
        nums1[j] = nums1[p];
        p--;
        j--;
    }
    while (z >= 0) {
        nums1[j] = nums1[z];
        z--;
        j--;
    }

}

int main()
{
   
    return 0;
}