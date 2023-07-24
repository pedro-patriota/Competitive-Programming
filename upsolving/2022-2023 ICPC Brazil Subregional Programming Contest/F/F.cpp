#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, c;
    cin >> n >> c;
    map<string, int> freqMap;
    multimap<int, string, greater<int>> invertFreqMap;

    for (int i = 0; i < n; i++)
    {
        bool alternate = false;
        string input, sufix = "", prefix = "";
        cin >> input;
        for (int j = 0; j < c; j++)
        {
            if (input[j] == '*')
            {
                alternate = true;
                continue;
            }
            if (alternate)
            {
                sufix += input[j];
            }
            else
            {
                prefix += input[j];
            }
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
            freqMap[prefix + i + sufix]++;
        }
    }

    for (auto val : freqMap)
    {
        //cout << val.first << " " << val.second << endl;
        invertFreqMap.insert(make_pair(val.second, val.first));
    }
    
    auto best = *invertFreqMap.begin();
    cout << best.second << " " << best.first;
    return 0;
}