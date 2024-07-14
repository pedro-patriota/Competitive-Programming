#include <bits/stdc++.h>
using namespace std;

/*
[[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]

*/

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), cnt = 1, ans = 0;
    bool rev = false;
    vector<pair<int, int>> coord (n*n + 1);
    for (int x = n -1; x >= 0; x--) {
        for (int y = 0; y < n; y++) {
            coord[cnt] = {x, rev ?  n -1 - y: y};
        }
        rev = !rev;
    }
    queue<int> q;
    vector<bool> vis (n*n + 1, false);
    q.push(1);

    while (not q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto v = q.front();
            q.pop();
            vis[v] = true;
            if (v == n*n) {
                return ans;
            }
            for (int nh = v + 1; nh <= min(n*n, v+6); nh++) {
                auto [x, y] = coord[nh];
                if (board[x][y] != -1 && not vis[nh]) {
                    q.push(board[x][y]);
                } else if (not vis[nh]) {
                    q.push(nh);
                }
            }
        }
        ans++;
    }
    return ans;
}

int main () {

}
