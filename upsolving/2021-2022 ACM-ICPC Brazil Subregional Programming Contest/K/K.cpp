#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int t, d, m;
    bool isPos = false;
    int lastTime = 0;
    cin >> t >> d >> m;

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        if (val - lastTime >= t)
        {
            isPos = true;
            break;
        }
        lastTime = val;
    }

    if (d - lastTime >= t || isPos)
    {
        cout << "Y" << endl;
        return 0;
    }
    else
    {
        cout << "N" << endl;
        return 0;
    }


    return 0;
}