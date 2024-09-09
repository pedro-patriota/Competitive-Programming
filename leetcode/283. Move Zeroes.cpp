#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input: nums = [0]
Output: [0]

0, 0, 1, 1, 1
1, 1, 1, 0, 0

1, 2, 3, 0, 0
1, 2, 3, 0, 0

[]
[]

1, 2, 3
1, 2, 3

-1, -2, 0, -3, 0
-1, -2, -3, 0, 0

1 Approach
0,1,0,3,12
         ^
1 3 12 0 0

1, 2, 3, 0, 0

1 2 3 0 0

Time Complexity: O(N)
Space Complexity: O(N)

2 Approach

low = 0
high = 0

1,3,12,0,0
         ^
            ^

Time complexity: O(N)
Space Complexity: O(1)

*/

void moveZeroes(vector<int>& arr) {
    int low = 0, high = 0, sz = arr.size();
    
    while (low < sz) {
        while (high < sz && arr[high] == 0) {
            high++;
        }
        if (high == sz) {
            arr[low] = 0;
            
        } else {
            arr[low] = arr[high];
            high++;
        }
        low++;
    }
}

void printArr(vector<int>& arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main () {
    vector<int> arr = {0,1,0,3,12};
    moveZeroes(arr);
    printArr(arr); 

    arr = {0};
    moveZeroes(arr);
    printArr(arr); 

    arr = {0, 0, 1, 1, 1};
    moveZeroes(arr);
    printArr(arr); 

    arr = {};
    moveZeroes(arr);
    printArr(arr); 

    arr = {1, 2, 3};
    moveZeroes(arr);
    printArr(arr); 

    arr = {-1, -2, 0, -3, 0};
    moveZeroes(arr);
    printArr(arr); 

}
