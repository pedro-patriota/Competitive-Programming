#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

string res = "";
void merge(string str){
    if (str.size() == 1){
        res += str;
        return;
    }

    string s1, s2;
    reverse(str.begin(), str.end());
    int half = str.size()/2;
    for (int i = 0; i < half ; i++){
        s1 += str[i];
    }
    for (int i = half; i < str.size(); i++){
        s2 += str[i];
    }
    merge(s1);
    merge(s2);


}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    merge(str);
    cout << res;

    
        
    return 0;
    
}