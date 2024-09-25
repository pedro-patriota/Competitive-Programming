#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int, int>> q;
    int m = maze.size(), n = maze[0].size(), dist = 0, sz;
    q.push({entrance[0], entrance[1]});
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while (q.size() > 0) {
        sz = q.size();
        while (sz--){
            auto [x, y] = q.front();
            q.pop();

            if (x != entrance[0] || y != entrance[1]) {
                if (x == 0 || x == m -1 || y == 0 || y == n - 1) {
                    return dist;
                }
            }

            for (auto [dir_x, dir_y] : dir) {
                int new_x = x + dir_x, new_y = y + dir_y;
                
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    if (not visited[new_x][new_y] && maze[new_x][new_y] == '.') {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        dist++;
    }
    return -1;
}

int main () {

}