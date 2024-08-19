#include <bits/stdc++.h>
using namespace std;

/*
[4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3]
5 3 7 4
k=4 ⇒ 0, k=5 ⇒ 2, k=6 ⇒ 5

[5, 4, 5, 3, 4, 1]
k = 3 => 1
5 4 5 x
4 5 3
5 3 4 
3 4 1 


k = 4 => 2
5 4 5 3 x  
4 5 3 4 x 
5 3 4 1 

[5, 5, 5, 3, 4, 1]
k = 3 => 2

[5, 4, 5] k = 10
-> -1

k > 0

[1, 1, 1] 
k = 1 => 3
k = 3 => 1

1. Brute force: For each subarray of size k, use a for loop to find duplicates 
time: O((n-k + 1)*k)
space: O(k)

2. Two pointer
    2.1 Initially create the first subarray of size K -> check if it has duplicates
    2.2 Hash map to count duplicates within the range
    2.3 Once we move the window, we remove the last and insert the next

k = 6 => 5
[4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3]
                   ^
                                  ^
cnt = 5
num_duplicates = 1

hash:
4 - 0
5 - 1
3 - 2
7 - 1
8 - 1
1 - 1
2 - 0

*/

int countDuplicates(vector<int> arr, int k) {
    if (k > arr.size()) {
        return -1;
    }
    if (k == 1) {
        return 0;
    }
    unordered_map<int, int> freq;
    int cnt = 0, num_duplicates = 0;

    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 1) {
            num_duplicates++;
        }
        freq[arr[i]]++;
    }
    if (num_duplicates > 0) {
        cnt++;
    }
    for (int right = k; right < arr.size(); right++) {
        int left = right - k + 1;
        int dec =  --freq[arr[left-1]];
        int inc =  ++freq[arr[right]];
        // cout << left << " " << right << " " <<  dec << " " << inc<< endl;
        if (dec == 1) {
            num_duplicates--;
        }
        if (inc == 2) {
            num_duplicates++;
        }
        if (num_duplicates > 0) {
            cnt++;
        }
    }
    return cnt;
}

int main () {
    cout << "Expected: 0 / Got: " << countDuplicates({4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3}, 1) << endl;
    cout << "Expected: 0 / Got: " << countDuplicates({4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3}, 4) << endl;
    cout << "Expected: 2 / Got: " << countDuplicates({4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3}, 5) << endl;
    cout << "Expected: 5 / Got: " << countDuplicates({4, 5, 3, 7, 4, 2, 3, 8, 7, 1, 5, 3}, 6) << endl;
    cout << "Expected: 1 / Got: " << countDuplicates({5, 4, 5, 3, 4, 1}, 3) << endl;
    cout << "Expected: 2 / Got: " << countDuplicates({5, 4, 5, 3, 4, 1}, 4) << endl;
    cout << "Expected: -1 / Got: " << countDuplicates({5, 4, 5, 3, 4, 1}, 10) << endl;
    cout << "Expected: 2 / Got: " << countDuplicates({5, 5, 5, 3, 4, 1}, 3) << endl;
    cout << "Expected: 2 / Got: " << countDuplicates({1, 1, 1}, 2) << endl;
}