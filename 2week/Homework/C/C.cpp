#include <bits/stdc++.h>
using namespace std;
long long n, n2, k, num_solutions, it;
vector<vector<bool>> table;

void handleSolution(vector<vector<bool>> table, int row, int column, int counter, int diagonal)
{
    it ++;
    table[row][column] = true;
    counter++;
    if (counter == k)
    {
        num_solutions += 1;
        return;
    }
    /* if (n2 - ocupied < k - counter){ // if the free spaces are less than I need
        return;
    } */

    for (int i = 1; i <= min((n-1) - column, (n-1) -row); i++)
    {
        
        table[row + i][column + i] = true;
    }
    for (int i = diagonal + 1; i <= (2 * n - 1) - (k - counter); i++)
    {
        if (i > n - 1)
        {
            int aux = i - (n - 1);
            int row = n -1;
            for (int j = aux; j <= n - 1; j++)
            {
                if (table[row][j] == false)
                {
                    handleSolution(table, row, j, counter, i);
                }
                row--;
            }
        }
        else
        {
            int row = i; 
            for (int j = 0; j <= i; j++)
            {
                if (table[row][j] == false)
                {
                    handleSolution(table, row, j, counter, i);
                }
                row--;
            }
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> n >> k;
        num_solutions = 0;
        if (n == 0 && k == 0)
        {
            break;
        }
        n2 = pow(n, 2);
        if (k >= 2*n - 1)   
        {
            cout << 0 << '\n';
            continue;
        }
        if (k == 0){
            cout << 1 << "\n";
        }
        
        table = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < (2 * n -1) - (k -1); i++)
        {
            if (i > n - 1)
            {
                int aux = i - (n - 1);
                int row = n-1;
                for (int j = aux; j <= n - 1; j++)
                {
                    
                    handleSolution(table, row, j, 0, i);
                    
                    row--;
                }
            }
            else
            {
                int row = i;
                for (int j = 0; j <= i; j++)
                {
                    
                    handleSolution(table, row, j, 0, i);
                    
                    row--;
                }
            }
        }
        cout << num_solutions << "\n";
    }
    return 0;
}