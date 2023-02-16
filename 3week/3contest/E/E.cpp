#include <bits/stdc++.h>
using namespace std;
long long string_len;
string res;
char colection[] = {'a', 'b', 'c'};
long long counter = 2;
bool a_b;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> string_len;
    if (string_len == 1){
        cout << "a";
        return 0;
    }
    if (string_len == 2){
        cout << "aa";
        return 0;
    }else{
        res = "aa";
        a_b = true;
        for (long long i = 2; i < string_len; i++){
            if (counter == 2){
                counter = 0;
                if (a_b){
                    a_b = false;
                }else{
                    a_b =true;
                }
            }
            if (a_b){
                res += "a";
            }else{
                res += "b";
            }
            counter ++;
        }
        cout << res;
        
    }
    
}