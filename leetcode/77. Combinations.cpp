#include <bits/stdc++.h>
using namespace std;

void make_comb(vector<vector<int>>& comb, vector<int>& curr, int i, int n, int k) {
    if (curr.size() == k) {
        comb.push_back(curr);
        return;
    }
    
    for (; i <= n; i++) {
        curr.push_back(i);
        make_comb(comb, curr, i + 1, n, k);
        curr.pop_back();
    }
}

vector<vector<int>> combine (int n, int k) {
    vector<vector<int>> comb;
    vector<int> curr;
    make_comb(comb, curr, 1, n, k);
    
    return comb;
}

int main () {

}
