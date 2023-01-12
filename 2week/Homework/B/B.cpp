#include <bits/stdc++.h>
using namespace std;

const int board_size = 8;
long long num_dataset, init_row, init_column;
vector<vector<int>> solutions_table;
void backtracking(vector<vector<int>> board, int num_queen, vector<int> temp_solution)
{
    if (num_queen == board_size)
    {
        solutions_table.push_back(temp_solution);
        return;
    }
    else
    {
        if (!temp_solution.empty() && temp_solution.back() != init_row)
        {
            int last_row = temp_solution.back();
            int last_col = num_queen - 1;

            for (int i = last_col; i < board_size; i++)
            {
                board[last_row][i] = 1;
            }

            for (int i = 1; i < board_size; i++)
            {

                if (last_row + i < board_size && last_col + i < board_size)
                {
                    board[last_row + i][last_col + i] = 1;
                }
                if (last_row - i >= 0 && last_col + i < board_size)
                {
                    board[last_row - i][last_col + i] = 1;
                }
            }
        }
        if (num_queen == init_column)
        {
            temp_solution.push_back(init_row);
            backtracking(board, num_queen + 1, temp_solution);
            return;
        }
        for (int row = 0; row < board_size; row++)
        {
            if (board[row][num_queen] == 0)
            {
                temp_solution.push_back(row);
                backtracking(board, num_queen + 1, temp_solution);
                temp_solution.pop_back();
            }
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_dataset;
    for (int i = 0; i < num_dataset; i++)
    {
        vector<vector<int>> board(board_size, vector<int>(board_size));
        solutions_table = vector<vector<int>>();
        cin;
        cin >> init_row >> init_column;
        init_row -= 1;
        init_column -= 1;
        for (int i = 0; i < board_size; i++)
        {
            board[init_row][i] = 1;
            // board[i][init_column] = 1;
        }
        for (int i = 1; i < board_size; i++)
        {

            if (init_row + i < board_size && init_column + i < board_size)
            {
                board[init_row + i][init_column + i] = 1;
            }
            if (init_row - i >= 0 && init_column - i >= 0)
            {
                board[init_row - i][init_column - i] = 1;
            }
            if (init_row - i >= 0 && init_column + i < board_size)
            {
                board[init_row - i][init_column + i] = 1;
            }
            if (init_row + i < board_size && init_column - i >= 0)
            {
                board[init_row + i][init_column - i] = 1;
            }
        }
        backtracking(board, 0, {});
        cout << "SOLN       COLUMN" <<"\n" << " #      1 2 3 4 5 6 7 8\n" << "\n";
        for (int i = 0; i < solutions_table.size(); i++){
            if (i+1 < 10){
               cout <<" "; 
            }
            cout <<i+1 << "     ";
            for (auto val : solutions_table[i]){
                cout << " " <<  val + 1;
            }
            cout << "\n";
        }
        if (i != num_dataset -1){
            
            cout << "\n";
        }
    }
}