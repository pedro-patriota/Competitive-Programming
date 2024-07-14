#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> visited;
int n, m;

bool is_valid (int x, int y) {
    if (x >= 0 && y >= 0 && x < m && y < n) {
        return true;
    }

    return false;
    
}

void dfs (int x, int y, vector<vector<char>>& board) {
    visited[x][y] = true;
   for (auto [dx, dy] : dir) {
        int newx = dx + x;
        int newy = dy + y;
        if (is_valid(newx, newy) && board[newx][newy] == 'O' && not visited[newx][newy]) {
            dfs (newx, newy, board);
        }
   }

}

void solve(vector<vector<char>>& board) {
    n = board.size();

    if (n == 0) {
        return;
    }
    m = board[0].size();
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i ++) {
        if (board[i][0] == 'O' && not visited[i][0]) {
            dfs(i, 0, board);
        }
        if (board[i][m -1] == 'O' && not visited[i][m-1]) {
            dfs(i, m-1, board);
        }
    }
    for (int y = 0; y < m; y++) {
        if (board[0][y] == 'O' && not visited[0][y]) {
            dfs(0, y, board);
        }
        if (board[n-1][y] == 'O' && not visited[n-1][y]) {
            dfs(n-1, y, board);
        }
    }   

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            if (not visited[i][y]) {
                board[i][y] = 'X';
            }
        }
    }
}

int main () {

}
