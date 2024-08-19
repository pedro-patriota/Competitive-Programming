#include <bits/stdc++.h>
using namespace std;
/*
Input: [3, 4, 1, 5, 4, 2, 3, 5, 3, 4]
Output: k=2 ⇒ 4, k=3 ⇒ 3

[3, 2, 1]
k = 2 -> -1

[]
k = 1 -> -1

k >= 1


-> time: O(n^2) - To do two inner loops to find which numbers are repeating itself
-> hash: Map the frequency of each number
    -> time: O(n)
    -> space: O(n)
*/

int findFirstOccurrence(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int ans = -1;
    if (k == 0) {
        return ans;
    }   
    for (auto v : arr) {
        freq[v]++;
        if (freq[v] == k) {
            ans = v;
            break;
        }
    }
    return ans;
}

/*
Last occurring
Input: [3, 4, 1, 5, 4, 2, 3, 5, 3, 4]
k = 3 => 4
k = 2 => 5
k = 1 => 2

*/

int findLastOccurrence(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int ans = -1;
    if (k == 0) {
        return ans;
    }   
    for (auto v : arr) {
        freq[v]++;
        if (freq[v] == k) {
            ans = v;
        }
    }
    return ans;
}

int main () {
    vector<int> input = {3, 4, 1, 5, 4, 2, 3, 5, 3, 4};
    cout << "Expected: 4 / Got: " <<findFirstOccurrence(input, 2) << endl;
    cout << "Expected: 3 / Got: " <<findFirstOccurrence(input, 3) << endl;
    cout << "Expected: -1 / Got: " <<findFirstOccurrence(input, 10) << endl;
    cout << "Expected: -1 / Got: " <<findFirstOccurrence(input, 0) << endl;
    
    cout << "Expected: 5 / Got: " <<findLastOccurrence(input, 2) << endl;
    cout << "Expected: 4 / Got: " <<findLastOccurrence(input, 3) << endl;
    cout << "Expected: 2 / Got: " <<findLastOccurrence(input, 1) << endl;
    cout << "Expected: -1 / Got: " <<findLastOccurrence(input, 10) << endl;
    cout << "Expected: -1 / Got: " <<findLastOccurrence(input, 0) << endl;


}