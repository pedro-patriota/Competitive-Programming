#include <bits/stdc++.h>
using namespace std;

/*
Spiral Traverse
Difficulty: 🟦 | Category: Arrays | Successful Submissions: 49,656+

Problem Statement:
Write a function that takes in an n x m two-dimensional array (that can be square-shaped when n == m) 
and returns a one-dimensional array of all the array's elements in spiral order.

Details:
Spiral order starts at the top left corner of the two-dimensional array, goes to the right, 
and proceeds in a spiral pattern all the way until every element has been visited.

array = [
    [1,  2,  3,  4],
    [12, 13, 14, 5],
    [11, 16, 15, 6],
    [10, 9,  8,  7],
]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

[
[1, 2]
]
-> [1, 2]

[
[1, 1, 1]
[1, 1, 1]
[1, 1, 1]
]
-> [1, 1, .... , 1]

[[1]]
-> [1]

1 Approach
[
[1, 2, 3]
[7, 6, 5]
[8, 9, 0]
]
0, 0 , 1, 1 ...

0,0 
1, 1
[1,  2,  3,  4],
[12, 13, 14, 5],
[11, 16, 15, 6],

ans = [1, 2, 3, 4, 5, 6, 15, 16, 11, 12, 13, 14]

convertToOneDimension(matrix, i, ans)

    sizeX = matrix.X -> 3
    sizeY = matrix.Y -> 4

    last_column = sizeY - i.y - 1 = 4 - 1- 1 = 2
    last_row = sizeX- i.x - 1 = 3 - 1- 1 = 1

    1, 2
    for it  i.y < sizeY - i.y it++
        ans.push(matrix[i.x, it])
    
    2 < 2
    for it i.x + 1 < sizeX - dig it--
        ans.push(matrix[it, last_column])
    
    1 >= 1
    for it last_coumn - 1 > dig
        ans.push(matrix[last_row][it])
    
    for it last_row - 1 > dig
        ans.push(matrix[it][i.x]])
    
*/


void convertDiagonalToOneDimension(vector<vector<int>>& matrix, int dig, vector<int>& ans) {
    int sizeX = matrix.size();
    int sizeY = matrix[0].size();

    if (dig >= sizeX || dig >= sizeY) {
        return;
    }

    int last_column = sizeY - dig - 1;
    int last_row = sizeX - dig - 1;

    // Direita para esquerda;
    for (int it = dig; it <  sizeY - dig; it++) {
        ans.push_back(matrix[dig][it]);
    }

    // Cima para baixo
    for (int it  = dig + 1; it < sizeX - dig; it++) {
        ans.push_back(matrix[it][last_column]);
    }

    // Esquerda para direita
    for (int it = last_column - 1; it > dig; it--) {
        ans.push_back(matrix[last_row][it]);
    }

    // Baixo para cima
    for (int it = last_row; it > dig; it--) {
        ans.push_back(matrix[it][dig]);
    }


}

void convertToOneDimension(vector<vector<int>>& matrix, vector<int>& ans) {
    int sizeX = matrix.size(), sizeY = matrix[0].size();
    int max_dig = max(sizeX/2, sizeY/2);
    

    for (int dig = 0; dig < max_dig; dig++) {
        convertDiagonalToOneDimension(matrix, dig, ans);        
    }
}

void printArr (vector<int> ans) {
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

}


int main () {
    vector<vector<int>> arr = {
        {1,  2,  3,  4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9,  8,  7},
    };
    vector<int> ans;

    convertToOneDimension(arr, ans);
    printArr(ans);

    arr = {
        {1, 2}
    };
    ans = {};
    convertToOneDimension(arr, ans);
    printArr(ans);

    arr = {
        {1,  2,  3,  4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
    };
    ans = {};
    convertToOneDimension(arr, ans);
    printArr(ans);

    arr = {
        {1},
        {2}
    };
    ans = {};
    convertToOneDimension(arr, ans);
    printArr(ans);

}