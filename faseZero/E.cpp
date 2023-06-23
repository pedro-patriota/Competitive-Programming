#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n;
    vector<ll> arr;
    set<ll> diff;
    map<ll, ll> diffFreq;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        diff.insert(x);
        diffFreq[x]++;
    }

    vector<ll> ans;
    vector<ll> finalPossibilities;
    vector<ll> possibilities1;
    vector<ll> possibilities2;
    for (auto difference : diff)
    {
        ll val = *arr.begin();
        ll pos1 = val - difference;
        ll pos2 = val + difference;
        possibilities1.push_back((pos1));
        possibilities1.push_back((pos2));
    }
    for (auto difference : diff)
    {
        auto last = arr.end();
        --last;
        ll val = *last;
        ll pos1 = val - difference;
        ll pos2 = val + difference;
        possibilities2.push_back((pos1));
        possibilities2.push_back((pos2));
    }
    sort(possibilities2.begin(), possibilities2.end());
    for (int i = 0; i < possibilities1.size(); i++)
    {
        ll val1 = possibilities1[i];
        if (binary_search(possibilities2.begin(), possibilities2.end(), val1))
        {
            finalPossibilities.insert(val1);
        }
    }
    for (auto pos : finalPossibilities)
    {
        // auto it  = arr.begin();
        bool isPos = true;
        map<ll, ll> seen;
        // cout << pos<< endl;
        for (int i = 0; i < n; i++)
        {

            ll nextVal = arr[i];
            ll ab = abs(nextVal - pos);
            // cout << "diferenca necessaria : " << ab << " valor da possibilidade " << pos << " valor atual " << nextVal << endl;
            // cout << ab << " " << nextVal << endl;
            if (not diff.count(ab) || seen[ab] == diffFreq[ab])
            {
                isPos = false;
                break;
            }
            seen[ab]++;
        }
        if (isPos)
        {
            ans.push_back(pos);
        }
    }

    for (auto val : ans)
    {
        cout << val << endl;
    }

    return 0;
}