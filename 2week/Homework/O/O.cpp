#include <bits/stdc++.h>
using namespace std;
int n, val, n2;
bool found,duplicated;
vector<vector<int>> table;
vector<vector<int>> solution;
vector<set<int>> column_set, row_set, box_set;

void backtracking(vector<set<int>> column_data, vector<set<int>> row_data, vector<set<int>> box_data
, int column, int row, 
vector<vector<int>> temp_table)
{
    if (found){
        return;
    };
    if (column == n2)
    {
        solution = temp_table;
        found = true;
    }
   /*  else if (column_data[column].empty() || row_data[row].empty())
    {
        return;
    } */
    else
    {

        if (temp_table[row][column] == 0)
        {
            for (auto it = column_data[column].begin(); it != column_data[column].end(); it)
            {
                int val = *it;
                if (row_data[row].count(val) && box_data[n*(column/n) + row/n].count(val))
                {
                    temp_table[row][column] = val;

                    row_data[row].erase(val);
                    box_data[n*(column/n) + row/n].erase(val);
                    column_data[column].erase(it++);
                    if (row + 1 > n2 - 1)
                    {
                        backtracking(column_data, row_data, box_data, column + 1, 0, temp_table);
                    }
                    else
                    {
                        backtracking(column_data, row_data, box_data, column, row + 1, temp_table);
                    }
                    column_data[column].insert(val);
                    box_data[n*(column/n) + row/n].insert(val);
                    row_data[row].insert(val);

                }
                else
                {
                    ++it;
                }
            }
        }
        else
        {
            if (row + 1 > n2 - 1)
            {
                backtracking(column_data, row_data, box_data, column + 1, 0, temp_table);
            }
            else
            {
                backtracking(column_data, row_data, box_data, column, row + 1, temp_table);
            }
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    bool first = true;
    while (cin >> n)
    {
        if (!first){
            cout << "\n";
        }
        found = false;
        duplicated = false;
        n2 = n * n;
        table = vector<vector<int>>(n2, vector<int>(n2));
        column_set = vector<set<int>>(n2);
        row_set = vector<set<int>>(n2);
        box_set = vector<set<int>>(n2);
        for (int i = 0; i < n2; i++)
        {

            for (int j = 1; j <= n2; j++)
            {

                row_set[i].insert(j);
                column_set[i].insert(j);
                box_set[i].insert(j);

            }
        }
        
        for (int i = 0; i < n2; i++)
        {

            for (int j = 0; j < n2; j++)
            {
                cin >> val;
                table[i][j] = val;
                if (val != 0)
                {    
                    if (!box_set[(j / n) * n + i / n].count(val) || !row_set[i].count(val) || !column_set[j].count(val))
                    {
                        duplicated = true;
                    }
                    box_set[(j/n)*n + i/n].erase(val);
                    row_set[i].erase(val);
                    column_set[j].erase(val);
                }
            }
            
        }
        if (duplicated){
            cout << "NO SOLUTION\n";
        }else{
            
            backtracking(column_set, row_set, box_set,  0, 0, table);
            if (found){
                for (int i = 0; i < n2; i++)
                {
    
                    for (int j = 0; j < n2; j++)
                    {
                        cout << solution[i][j];
                        if (j < n2-1)
                        {    
                            cout << " ";
                        }
                    }
                    cout << "\n";
                }
            }else{
                cout << "NO SOLUTION\n";
            }
        }
        first = false;
    }
        return 0;
}