#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve(){
    string s1; cin >> s1;
    ll n; cin >> n;

    int sz = s1.size();
    multiset<char> table;
    for (int i = 0; i < sz; i++) table.insert(s1[i]);
    vector<bool> del(sz);
    vector<bool> used(sz);
    queue<int> rem;
    stack<int> st;
    for (int i = 0; i < sz; i++){

        auto it = table.find(s1[i]);
        st.push(i);
        if (it != table.begin()){
            rem.push(i);
            st.pop();
        }else{
            while (not st.empty()){
                int x = st.top();
                rem.push(x);
                st.pop();
            }
        }
        table.erase(it);
    }
    //for (int i = sz - 1; i >= 0; i--) if (not used[i]) rem.push(i); 
    
    while (n - sz > 0){
        int x = rem.front();
        del[x] = true;
        rem.pop();
        
        n -= sz;
        sz--;
    }   
    n -= 1; // cnt comeca em 0
    int qnt = 0;
    for (int i = 0; i < s1.size(); i++){
        if (not del[i]){
            if (n == qnt){
                cout << s1[i];
            }
            qnt++;
        }
    }


}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}