#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<char> alphabetX(26);
const int max_L = 1e4 + 5;
vector<set<char>> seg (max_L);

void build(set<char> v, int l, int r, int idx){
    if (l == r){
        seg[idx] = v;
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    build(v, l, m, left);
    build(v, m+1, r, right);

    seg[idx] = seg[left] + seg[right];
}

void solve (int begin, int end){
    
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 26; i++)
    {
        alphabetX[i] = 'a' + i;
    }
    string A = "", B = "";
    int qnt, num;
    for (auto letter : alphabetX)
    {
        A += letter;
    }
    solve(0, 13);
    cout << "? " << A+B << endl
         << flush;
    set<char> output;
    vector<set<char>> pos_letter (1e4 + 5);
    cin >> qnt;


    return 0;
}