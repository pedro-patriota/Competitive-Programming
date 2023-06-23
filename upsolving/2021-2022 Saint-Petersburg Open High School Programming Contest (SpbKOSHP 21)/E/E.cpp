#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    string word;
    cin >> n;
    vector<int> phonetic_points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        int pont = 0;
        int aux = 0;
        for (auto letter : word)
        {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            {
                if (pont == aux)
                {
                    pont++;
                }
            }
            else
            {
                aux = pont;
            }
        }
        phonetic_points[i] = pont;
    }
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + phonetic_points[i];
    }
    
    ll counter = 0;
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(prefix.begin(), prefix.end(), prefix[i] - 7);
        if (it != prefix.end() && it != prefix.begin() && *it == prefix[i] - 7)
        {
            if (binary_search(prefix.begin(), prefix.end(), *it - 5) && binary_search(prefix.begin(), prefix.end(), prefix[i] + 5)){
                counter++;
            }
        }
    }
    cout << counter;

    return 0;
}