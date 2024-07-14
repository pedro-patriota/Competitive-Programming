#include <bits/stdc++.h>
using namespace std;

pair<int, int> findPos(int x, int m, int n) { return {x / n, x % n}; }

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m, n, med, l, r;
    m = matrix.size();
    n = matrix[0].size();
    l = 0;
    r = m * n - 1;

    while (l < r)
    {
        med = (l + r) / 2;
        auto [line, column] = findPos(med, m, n);
        cout << line << " " << column << " " << matrix[line][column]
             << endl;
        if (matrix[line][column] > target)
        {
            r = med;
        }
        else if (matrix[line][column] == target)
        {
            return true;
        }
        else
        {
            l = med + 1;
        }
    }
    auto [line, column] = findPos(l, m, n);
    if (matrix[line][column] == target)
    {
        return true;
    }

    return false;
}

int main()
{
}