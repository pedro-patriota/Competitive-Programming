#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int countingSubstrings(string s) {
    int n = (int)s.length();
    int ans = 0;
    for (int j = 1; j <= n; j++){
        int maxPi = 0;
        vector<int> pi(n);
        for (int i = 1; i < j; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
            maxPi= max(maxPi, pi[i]);
        }
        ans += j  - maxPi;

    }
    return ans;
}





int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string s = "ab";
    cin >> s;
    auto vec = kmp(s);
    for (auto val : vec){
        cout << val << " ";
    }
    cout << endl;
    cout << countingSubstrings(s);
    ll n = s.size();
    ll k = n - vec[n - 1];
    cout << endl;
    if (n%k == 0){
        cout << s.substr(0, k);
    }else{
        cout << "not compressable";
    }
     
        
    return 0;
    
}