#include <bits/stdc++.h>
using namespace std;
long long n, n2, k, num_solutions, it;
vector<set<int>> diagonal_table;

void handleSolution(vector<set<int>> table, int row, int counter, int diagonal)
{
    counter++;
    if (counter == k)
    {
        num_solutions += 1;
        return;
    }
    /* if (n2 - ocupied < k - counter){ // if the free spaces are less than I need
        return;
    } */
    int marked_diagonal = diagonal + 2;
    int desired_val = row +1;

    while (marked_diagonal < 2*n -1){
        if (table[marked_diagonal].count(desired_val)){
            table[marked_diagonal].erase(desired_val);
        }else{
            break;
        }
        marked_diagonal += 2;
        desired_val ++;
    }
    
    for (int i = diagonal + 1; i <= (2 * n - 1) - (k - counter); i++)
    {
        for (auto val : table[i]){
            handleSolution(table, val, counter, i);
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
        if (k >= 2 * n - 1)
        {
            cout << 0 << '\n';
            continue;
        }
        if (k == 0)
        {
            cout << 1 << "\n";
        }

        diagonal_table = vector<set<int>>(2 * n - 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                diagonal_table[i].insert(j);
            }
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i; j <= n -1; j++)
            {
                diagonal_table[n + i-1].insert(j);
            }
        }
        for (int diagonal = 0; diagonal < (2 * n - 1) - (k - 1); diagonal++)
        {

            for (auto it : diagonal_table[diagonal])
            {

                handleSolution(diagonal_table, it, 0, diagonal);
            }
        
        }
        cout << num_solutions << "\n";
    }
    return 0;
}