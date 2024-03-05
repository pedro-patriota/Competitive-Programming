#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

int main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int tests, rem, ins, n; 
    cin >> tests;
    while (tests--){

        string s1, s2;
        rem = ins = 0;
        cin >> n >> s1 >> s2;
        for (int i = 0; i < n; i++){
            if (s1[i] == '1' && s2[i] == '0') rem++;
            if (s1[i] == '0' && s2[i] == '1') ins++;
        }
        cout << (rem + ins) - min(rem, ins) << endl;

    }
}