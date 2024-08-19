#include <bits/stdc++.h>
using namespace std;

/*
1. array is aleary sorted
2. can not use the same index multiple times
3. its is guarenteed that one and only one solution exists

numbers = 
[2,7,11,15]
 ^ ^

partial_sum = 2 + 7 = 9

target = 9

[2,3,4]
 ^   
     ^

parital_sum = 2 + 4 = 6

target = 6

[2,7,11,15]
   ^      
      ^

partial_sum = 7 + 11
target = 18

time = O(n)
space = O(1)
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    int sz = numbers.size(), l = 0, r = sz -1, part_sum;
    while (true) {
        part_sum = numbers[l] + numbers[r];
        if (part_sum == target) {
            return {l+1, r+1};
        } else if (part_sum < target) {
            l++;
        } else {
            r--;
        }
    }    
    return {-1, -1};
}
