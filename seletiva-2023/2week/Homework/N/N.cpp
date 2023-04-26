#include <bits/stdc++.h>
using namespace std;

string input1,  input2;
int mid;

bool merge(int left, int right){
    if (left < right){
        if (input1 == input2){ // talvez comparar a qnt de letras
            return true;
        }else{
            if ((right - left)%2 == 1){
                return false;
            }
            
        }
        int mid = (left + right)/2;
        string left_part1 = ""; // mover a declaracao para global
        string right_part1 = "";
        string left_part2 = ""; 
        string right_part2 = "";
        for (int i = left; i < mid; i++){
            left_part1 += input1[i];
            left_part2+= input2[i];
            
        }
        for (int i = mid; i < right; i++){
            right_part1 += input1[i];
            right_part2 += input2[i];
        }
        input1 = left_part1;
        input2 = left_part2;
        if (!merge(left, mid)){
            input1 = left_part1;
            input2 = right_part2;
            if (merge( left, mid)){
                input1 = right_part1;
                input2 = left_part2;
                return merge( left, mid);            
            }else{
                return false;
            }
        }else{
            input1 = right_part1;
            input2 = right_part2;
            return merge( left, mid);            
        }
    }
    return false;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    map<char, int>table1;
    map<char, int>table2;
    cin >> input1;
    cin >> input2;
    int size = input1.size();
    
    for (int i = 0; i < size; i++){
        table1[input1[i]]++;
        table2[input2[i]]++;
    }
    if (table1 != table2){
        
        cout << "NO";
    }else{
    
        if (merge( 0, size)){
            cout << "YES";
        }else{
            cout << "NO";
        }
        
    }

    
}