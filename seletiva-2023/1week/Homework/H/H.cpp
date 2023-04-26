#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string> table;

    string english, foreign, input;
    while (getline(cin, input)){
        if (input == ""){
            break;
        }
        stringstream ss(input);
        
        ss >> english;
        ss >> foreign;
        
        table[foreign] = english;
        
    }
    while (getline(cin, foreign)){
        if (table.count(foreign)){
            cout << table[foreign] << "\n";
        }else{
            cout << "eh\n";
        }
    }



}