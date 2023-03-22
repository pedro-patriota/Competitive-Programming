#include <bits/stdc++.h>
using namespace std;
#define ll long long
string input, aux;
set<string> ans;

void solve(string temp, multiset<char> arr)
{
    if (temp.size() == input.size())
    {
        ans.insert(temp);
    }
    if (arr.size() > 0)
    {
        auto copy = arr;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            auto first = *it;
            auto itr = copy.find(first);
            if (itr != copy.end())
            {
                copy.erase(itr);
            }
            solve(temp + first, copy);
            copy.insert(first);
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;
    multiset<char> arr_;

    for (int i = 0; i < input.size(); i++)
    {
        arr_.insert(input[i]);
    }
    solve("", arr_);
    cout << ans.size() << "\n";
    for (auto val : ans)
    {
        cout << val << "\n";
    }
}