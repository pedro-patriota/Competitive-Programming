#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string input;
    int K;
    ll ans = 0;
    cin >> input >> K;
    for (int i = 0; i < input.size(); i++){
        vector<int>diff (input.size());
        for (int j = i; j < input.size(); j++){
            if (j == i){
                ans++;
                continue;
            }
            if ((j-i)%2 == 1){

            }else{
                
            }
            if (input[i] == input[j]){
                diff[j] == diff[j-1];
            }
            else{
                diff[j] += diff[j-1];
            }

        }
    }
    
        
    return 0;
    
}