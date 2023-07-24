#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    string input, crib;
    cin >> input;
    cin >> crib;

    vector<set<char>> alfa(input.size());
    ll ans = 0;
    for (int i = 0; i <= input.size() - crib.size(); i++)
    {
        bool is_pos = true;
        for (int j = 0; j < crib.size(); j++)
        {
            //cout << input[j+i] << " " << crib[j ] << endl;
            if (input[j+i] == crib[j ]){
               // cout << input[j+i] << " " << crib[j ]<< "!!!!!!" << endl;
                is_pos = false;
                break;
            }
        }
        if (is_pos) ans++;
    }
    cout << ans;

    return 0;
}