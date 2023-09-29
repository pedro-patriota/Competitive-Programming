#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n, k, number, color;
    cin >> n >> k;
    vector<ii> arr (n + 1);
    for (int i = 1; i <= n ; i++){
        cin >> number >> color;
        arr[i] = {number, color};
    }
    bool isPos = true;
    for (int i = 1; i <= n; i++){
        auto [number, color] = arr[i];
        if (number == i){
        continue;
            
        } 
        else if (arr[number].Y == color) {
            continue;
        }else{
            isPos = false;
            break;
        } 
        
    }
    if (isPos){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    
        
    return 0;
    
}