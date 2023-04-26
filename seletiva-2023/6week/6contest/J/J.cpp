#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll aux, length, last_num;
string n, last_num_str;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == "0"){
        cout << 4;
        return 0;
    }
    length = n.size();
    if (length == 1){
        last_num_str += (n[length -1]);
    }else{
        last_num_str += (n[length -2]);
        last_num_str += (n[length -1]);

    }
    last_num = stoi(last_num_str);
    aux += 1;

    if (last_num%2 == 0){
        aux += 6;
    }else{
        aux += 4;
    }

    if ((last_num)%4 == 0){
        aux+=1;
        aux += 6;
        
    }else if ((last_num)%4 == 1){
        aux += 3;
        aux += 2;
        
    }
    else if ((last_num)%4 == 2){
        aux+=9;
        aux += 4;
    }
    else if ((last_num)%4 == 3){
        aux+=7;
        aux += 8;
    }
    cout << aux%5 ;
  

    
}