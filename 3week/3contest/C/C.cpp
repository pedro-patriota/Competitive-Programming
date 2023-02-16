#include <bits/stdc++.h>
using namespace std;
string number;
long long k, counter;


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> number >> k;
    if (number == "0"){
        cout << 0;
        return 0;
    }
    if (number.length() -1 < k){
        cout << number.length() - 1;
        return  0;
    }

    for (int i = number.length() -1; i > 0; i--){
        if (k == 0){
            break;
        }
        if (number[i] == '0'){
            k--;
        }
        else{
            counter++;
        }
    }    
    cout << counter;
}