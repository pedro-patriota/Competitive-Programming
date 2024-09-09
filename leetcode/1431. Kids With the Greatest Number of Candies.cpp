#include <bits/stdc++.h>
using namespace std;

/*

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

extraCandies == O X

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 

1 Approach 
Get max
Compare each kid's candy with the max

Time: O(n)
Space: O(n)
*/

vector<bool> kidsWithCandies(vector<int>& arrKids, int extraCandies) {
    int max = *max_element(arrKids.begin(), arrKids.end());
    int sz = arrKids.size();
    vector<bool> ans(sz, false);
    for (int i = 0; i < sz; i ++) {
        if (arrKids[i] + extraCandies >= max) {
            ans[i] = true;
        }
    }
    return ans;
}

void printArr(vector<bool> ans) {
    for (auto v :  ans ) {
        cout << v << " ";
    }
    cout << endl;
}

int main () {
    vector<int> arrKids = {2,3,5,1,3};
    printArr(kidsWithCandies(arrKids, 3));
    arrKids = {4,2,1,1,2};
    printArr(kidsWithCandies(arrKids, 1));
    arrKids = {12, 1, 12};
    printArr(kidsWithCandies(arrKids, 10));
    arrKids = {1, 2, 1};
    printArr(kidsWithCandies(arrKids, 1));
    
}