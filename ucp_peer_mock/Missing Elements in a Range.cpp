#include <bits/stdc++.h>
using namespace std;

/*
Input: [8, 12, 18, 11, 15], lo = 7, hi = 16
Output: [7, 9, 10, 13, 14, 16]

[]  lo = 7, hi = 16
-> [1, 2, 3, ..., 16]

[2, 3, 4, 5]  lo = 7, hi = 16
[1, 2, 3, ... , 16]

[20, 21, 30, 22]  lo = 7, hi = 16
[1, 2, 3, ..., 16]

lo > hi -> return []
lo && hi >= 0

1. Brute force -> two inner lops and for each index in range we use a for loop to search for that value 
time: O(n^2)
space: O(1)
2. Hash: Map the occurrence of each number
    2.1 Go through the array and check in the inex in the range exists in hash
time: O(n)
space: O(min(n,k))

*/

vector<int> findMissingValues(vector<int>& arr, int lo, int hi) {
    if (lo > hi) return {};
    unordered_set<int> exists;
    vector<int> ans;
    for (auto v : arr) {
        if (v >= lo && v <= hi) {
            exists.insert(v);
        }
    }
    for (; lo <= hi; lo++) {
        if (not exists.count(lo)) {
            ans.push_back(lo);
        }
    }
    return ans;
}

void printArr(vector<int> arr) {
    for (auto v : arr) {
        cout << v << " ";
    }
    cout << endl;
}

int main () {
    vector<int> input = {8, 12, 18, 11, 15};
    cout << "Expected values: 7, 9, 10, 13, 14, 16" << endl << "Got: ";
    printArr(findMissingValues(input, 7, 16));

    input = {};
    cout << "Expected values: 7, 8, 9, 10, 11, 12, 13, 14, 15, 16" << endl << "Got: ";
    printArr(findMissingValues(input, 7, 16));
    printArr(findMissingValues(input, 7, 16));

    input = {2, 3, 4, 5};
    cout << "Expected values: 7, 8, 9, 10, 11, 12, 13, 14, 15, 16" << endl << "Got: ";
    printArr(findMissingValues(input, 7, 16));

    input = {20, 21, 50, 22};
    cout << "Expected values: 7, 8, 9, 10, 11, 12, 13, 14, 15, 16" << endl << "Got: ";
    printArr(findMissingValues(input, 7, 16));

    cout << "Expected values: " << endl << "Got: ";
    printArr(findMissingValues(input, 16, 6));
}