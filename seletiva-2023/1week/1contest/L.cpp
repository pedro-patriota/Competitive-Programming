#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main(){
    int col, row;
    char district;
    cin >> col;
    cin >> row;
    unordered_map<int, int> y;
    unordered_map<int, int> x;

    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j ++){
            cin >> district;
            if (district == '*'){
                y[i] += 1;
                x[j] += 1;
            }
        }
    }
    unordered_map<int, int> :: iterator it;
    int pos_y, pos_x;
    for (it = y.begin(); it != y.end(); ++it ){
        if (y[it->first] == 1){
            pos_y = it->first + 1;
            break;
        }
    }
    for (it = x.begin(); it != x.end(); ++it ){
        if (x[it->first] == 1){
            pos_x = it->first + 1;
            break;
        }
    }
    cout << pos_y << " " << pos_x;

    return 0;
}