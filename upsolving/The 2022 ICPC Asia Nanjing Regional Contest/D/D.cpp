#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second


int n, k, m;
ll c, d;
vector<int> arr;

ll l, r, med;

bool isPos (ll x){
    int ones = 0;
    vector<int> prefixNewOnes (n + 2);
    vector<int> NewOnes (n + 2);
    vector<int> BackToZero (n + 2);
    vector<int> prefixBackToZero (n + 2);

    for (int i =1; i <= n; i ++){
        if (arr[i] >= x){
            ones++;
            continue;
        }
        int maxI = min(i - 1 , m - 1);
        ll maxV = arr[i] + (c + d*maxI);
        if (maxV < x) continue;
        NewOnes[i - maxI]++;
            
        ll aux = (arr[i] + c);
        int position =   ceil(((double) (x - aux) )/(double) d);
        position = max(position, 0);
        BackToZero[i - (position - 1)]++;
    }
    for (int i = 1; i <= n - m + 1; i++){
        prefixNewOnes[i] = prefixNewOnes[i - 1]  + NewOnes[i];
        prefixBackToZero[i] = prefixBackToZero[i - 1]  + BackToZero[i];
    }
    int bestVal = -1;
    for (int i = 1; i <= n - m + 1; i++){
        bestVal = max(prefixNewOnes[i] - prefixBackToZero[i], bestVal);
    }

    if (ones + bestVal >= k) return true;
    return false;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m >> c >> d;
    arr = vector<int>(n + 1);

    for (int i = 1; i <= n ; i++){
        cin >> arr[i];
        l = min(l, (ll) arr[i]);
        
    }  
    r = 4e15;
    while (l < r)
    {
        med = (l + r + 1)/2;
        if (isPos(med)){
            l = med;
        }else{
            r = med - 1;
        }
    }

    cout << l << endl;
    
        
    return 0;
    
}