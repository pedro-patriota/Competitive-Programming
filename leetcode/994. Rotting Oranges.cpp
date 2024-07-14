#include <bits/stdc++.h>
using namespace std;



int m, n;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int x, int y, vector<vector<bool>>& markedGrid, vector<vector<char>>& grid) {
    markedGrid[x][y] = true;

    for (auto [xD, yD] : dir) {
        int new_x = x + xD, new_y = y + yD;

        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
            if (not markedGrid[new_x][new_y] && grid[x][y] == '1') {
                dfs(new_x, new_y, markedGrid, grid);
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> markedGrid(m, vector<bool>(n, false));
    int ans = 0;

    for (int x = 0; x < m; x ++) {
        for (int y = 0; y < n; y++) {
            if (grid[x][y] == '1'&& not markedGrid[x][y]) {
                dfs(x, y, markedGrid, grid);
                ans++;
            }
        }
    }

    return ans;


}

int main()
{

}