#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int num_digit, sum = 0;
    cin >> num_digit;
    vector<int>map;
    string input;
    cin >> input;
    char last_char;
    int num_zero = 0;

    for (int i = 0; i < num_digit; i++){
        if (input[i] == '1'){
            sum += 1;
        }
        else{
            map.push_back(sum);
            sum = 0;
        }
        last_char = input[i];
    }
    if (sum > 0){
        map.push_back(sum);
    }else{
        map.push_back(0);
    }
    for (auto val : map){
        cout << val;
    }
}