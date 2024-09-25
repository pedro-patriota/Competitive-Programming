#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> row_freq;
    int n = grid.size(), ans = 0;

    for (int row = 0; row < n; row++) {
        row_freq[grid[row]]++;
    }
    for (int column = 0; column < n; column++) {
        vector<int> col (n);
        for (int row = 0; row < n; row++) {
            col[row] = grid[row][column];
        }
        if (row_freq.count(col)) {
            ans += row_freq[col];
        }
    }
    
    return ans;
}

int main () {

}