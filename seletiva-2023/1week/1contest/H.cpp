#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    unordered_map<int, string> table;
    table[0] = "Anjan";
    table[1] = "Sufian";
    table[2] = "Alim";
    table[3] = "Shipu";
    table[4] = "Shoel";
    table[5] = "Sumon";
    int day;
    int counter = 0;
    while (true)
    {   
        cin >> day;
        if (day == 0){
            break;
        }else{
            cout << "Case " << counter<< ": " << table[day -1%6]; 
        }
        counter ++;
    }
    
}