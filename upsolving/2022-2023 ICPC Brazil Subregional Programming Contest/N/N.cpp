#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, l, frontSum = 0, backSum = 0, ans = 0, minBuffer = 0, sumBuffer = 0;
    cin >> n;
    vector<ll> A (n), B(n);
    vector<ll> prefix(n + 1);
    vector<ll> sufix(n + 1);
    for (int i = 0; i < n ; i++) cin >> A[i];
    for (int i = 0; i < n ; i++) cin >> B[i];
    for (int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + A[i];
        sufix[i+1] = sufix[i] + A[n-i-1];
    }
    multiset<ll, greater<ll>> notChoosen;
    multiset<ll> setBack;
    cin >> k >> l;
    vector<ll> sumBufferArr (k+1);
    for (int i = 0; i < k; i++){
        if (setBack.size() < l){
            sumBuffer += B[i];
            setBack.insert(B[i]);

        }else if (B[i] > *setBack.begin()){
            sumBuffer += B[i] - *setBack.begin();
            setBack.erase(setBack.begin());
            setBack.insert(B[i]);
        }
    }
    for(int i = 0; i < k; i++) if (not setBack.count(B[i])) notChoosen.insert(B[i]);
    sumBufferArr[0] = sumBuffer;
    for (int i = 1; i <=  k; i++){
        ll del = B[k - i];
        ll in = B[n - i];

        if (setBack.count(del)){
            ll substitute;
            sumBufferArr[i] -= del;
            setBack.erase(setBack.find(del));
            
            notChoosen.insert(in);
            
            substitute = *notChoosen.begin();
            setBack.insert(substitute);
            notChoosen.erase(notChoosen.begin());
            
            sumBufferArr[i] += sumBufferArr[i-1] +  substitute;

        }else{
            notChoosen.erase(notChoosen.find(del));
            if (in > *setBack.begin()){
                sumBufferArr[i] += sumBufferArr[i-1] +  in - *setBack.begin();

                notChoosen.insert(*setBack.begin());
                setBack.erase(setBack.begin());
                setBack.insert(in);

            }else{
                notChoosen.insert(in);
                sumBufferArr[i] = sumBufferArr[i-1];
            }
        
        }
    }




    for (int i = k;  i >= 0; i--){
        ll sumLeft = prefix[i];
        ll sumRight = sufix[k-i];


        //cout << ans << " " << sumLeft << " " << sumRight << " " << sumBufferArr[k-i] << endl;
        
        //cout << sumLeft + sumRight + sumBuffer << " " << sumBuffer << endl;
        ans = max(ans, sumLeft + sumRight + sumBufferArr[k-i]);
        
    }
    
    cout << ans;

    return 0;
    
}