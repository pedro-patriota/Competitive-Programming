#include <bits/stdc++.h>
#define tt tuple<int, int, int>
using namespace std;


vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
const int INF = 1e9;

int minPathSum(vector<vector<int>>& grid) {
    priority_queue<tt, vector<tt>, greater<tt>> pq;


    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> best (m, vector<int> (n, INF));

    pq.push({grid[0][0], 0, 0});
    best[0][0] = grid[0][0];
    
    while (not pq.empty()) {
        auto [val, x, y] = pq.top();
        pq.pop();

        if (val > best[x][y]) {
            continue;
        }

        for (auto [dirX, dirY] : dir) {
            int newX = x + dirX;
            int newY = y + dirY;
            if (newX < m && newY < n) {
                if (val + grid[newX][newY] < best[newX][newY]) {
                    best[newX][newY] = val + grid[newX][newY];
                    pq.push({best[newX][newY], newX, newY});
                }
            }
        }
    }

    return best[m -1][n -1];
}   


int main()
{
    
}