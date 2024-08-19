#include <bits/stdc++.h>
using namespace std;

/*
1. Give each kid a chocolate from lowest to high rank
    1.1 candy[i] = max(candy[i-1] >= 0, candy[i+1] < n) + 1
    1.2 OlogN
2. Use longest increasing squence?
    2.3 Add +1 candy while poping the queue?
    2.2 Use a queue to store the current squence 

q =  
3 1 2 6 1 2 5 4 3 0
              ^

2 1 2 3 1 2 3 1 1 X


*/

int candy(vector<int>& ratings) {
    int sz = ratings.size();
    vector<int> ans (sz, 1);
    for (int i = 1; i < sz; i++) {
        if (ratings[i] > ratings[i-1]) {
            ans[i] = ans[i-1] + 1;
        }
    }
    for (int i = sz - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            ans[i] = ans[i+1] + 1;
        }
    }
    return accumulate(ans.begin(), ans.end(), 0);
}

int candy(vector<int>& ratings) {
    int sz = ratings.size();
    if (sz == 1) {
        return 1;
    }
    vector<pair<int, int>> freq (sz);
    vector<int> ans (sz, 0);
    for (int i = 0; i < sz; i++) {
        freq[i] = {ratings[i], i};
    }
    sort(freq.begin(), freq.end());
    for (int i = 0; i < sz; i++) {
        auto [rat, pos] = freq[i];
        if (pos == 0) {
            ans[pos] = ans[pos + 1] + 1;
        } else if (pos == sz -1) {
            ans[pos] = ans[pos -1] + 1;
        } else {
            ans[pos] = max(ans[pos + 1], ans[pos -1]) + 1;
        }
    }
    return accumulate(ans.begin(), ans.end(), 0);
}
