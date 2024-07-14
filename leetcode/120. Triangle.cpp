#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int sz = triangle.size() - 1;

    for (; sz >= 1; sz--) {
        for (int i = 0; i <= sz - 1; i++) {
            triangle[sz - 1][i] = min(triangle[sz][i], triangle[sz][i + 1]);
        }
    }
    return triangle[0][0];
}