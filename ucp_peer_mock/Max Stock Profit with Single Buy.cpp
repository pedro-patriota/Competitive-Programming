#include <bits/stdc++.h>
using namespace std;

/*
50, 48, 44, 49, 31, 36, 32, 39, 51, 26, 25, 28
20 (buy at 31, sell at 51)

ans = max(0, ans)

31
=> 0

31 20 5
=> 0

arr[i] >= 0

[]
=> 0

1, 5, 10, 3
=> 9

2 2 2
=> 0

ans = max(ans, right - left)
ans = 20
left = 25
right = 25
50, 48, 44, 49, 31, 36, 32, 39, 51, 26, 25, 28
                                             ^
                                    ^

1. Two pointer solution
2. First pointer moves through the array
3. Second // is the lowest value found

31, 49, 48, 50, 51, 26, 25, 28

1 2 2 0
*/

int findUnlimitedBestSell(vector<int>& arr) {
    int left = arr[0], last = arr[0], ans = 0;
    for (auto right : arr) {
        if (right < last) {
            ans += last - left;
            left = right;
        }
        last = right;
    }
    if (last-left > 0) {
        ans += last - left;
    }
    return ans;
}

int findBestSell(vector<int>& arr) {
    int left = 1e9, ans = 0;
    for (auto right : arr) {
        if (right < left) {
            left = right;
        }
        ans = max(ans, right - left);
    }
    return ans;
}

int main () {
    vector<int> arr = {50, 48, 44, 49, 31, 36, 32, 39, 51, 26, 25, 28};
    cout << "Expected: 20 / Got: " << findBestSell(arr) << endl;

    arr = {31};
    cout << "Expected: 0 / Got: " << findBestSell(arr) << endl;

    arr = {31, 20, 5};
    cout << "Expected: 0 / Got: " << findBestSell(arr) << endl;

    arr= {1, 5, 10, 3};
    cout << "Expected: 9 / Got: " << findBestSell(arr) << endl;

    arr= {2, 2, 2};
    cout << "Expected: 0 / Got: " << findBestSell(arr) << endl;

    arr = {31, 49, 48, 50, 51};
    cout << "Expected: 21 / Got: " << findUnlimitedBestSell(arr) << endl;

    arr = {31, 49, 48, 50, 51, 26, 25, 28};
    cout << "Expected: 24 / Got: " << findUnlimitedBestSell(arr) << endl;

    arr = {1, 2, 2, 3, 0};
    cout << "Expected: 2 / Got: " << findUnlimitedBestSell(arr) << endl;

}