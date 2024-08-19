#include <bits/stdc++.h>
using namespace std;

void fillChessBoardvector(vector<vector<int>>& possibleChess, int i, int j, int propagation, int sz) {

    for (int column = j; column < sz; column++) {
        possibleChess[i][column] += propagation;
    }
    int dig = 1;
    for (int column = j + 1; column < sz; column++) {
        if (i + dig < sz) {
            possibleChess[i + dig][column] += propagation;
        }
        if (i - dig >= 0) {
            possibleChess[i - dig][column] += propagation;
        }
        dig++;
    }

}

void findNqueensComb(vector<vector<int>>& possibleChess, int column,
                        int& cnt) {
    int sz = possibleChess.size();
    if (column == sz) {
        cnt++;
    } else {
        for (int row = 0; row < sz; row++) {
            if (possibleChess[row][column] == 0) {
                fillChessBoardvector(possibleChess, row, column, 1, sz);
                findNqueensComb(possibleChess, column + 1, cnt);
                fillChessBoardvector(possibleChess, row, column, -1, sz);
            }
        }
    }
}

int totalNQueens(int n) {
    vector<vector<int>> possibleChess(n, vector<int>(n, 0));
    int cnt = 0;
    findNqueensComb(possibleChess, 0, cnt);
    return cnt;
}