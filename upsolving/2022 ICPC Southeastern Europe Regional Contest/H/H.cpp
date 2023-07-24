#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define br '\n'
// #define endl '\n'
#define X first
#define Y second
#define ii pair<int, int>
#define pii ii
const bool multitest = 0;
stack<ll> p1, p2, p3;
vector<pair<ll, ll>> moves;
ll valTop2, valTop3;

void unStack(int i)
{
    while (p2.size() > 0 || (p3.size() > 0 && p3.top() != i + 1))
    {
        if (p2.size() == 0)
        {
            valTop3 = p3.top();
            p1.push(valTop3);
            p3.pop();

            moves.push_back(make_pair(3, 1));
            continue;
        }
        if (p3.size() == 0)
        {
            valTop2 = p2.top();
            p1.push(valTop2);
            p2.pop();

            moves.push_back(make_pair(2, 1));
            continue;
        }
        if (p3.top() < p2.top())
        {
            valTop3 = p3.top();
            p1.push(valTop3);
            p3.pop();
            moves.push_back(make_pair(3, 1));
        }
        else
        {
            valTop2 = p2.top();
            p1.push(valTop2);
            p2.pop();
            moves.push_back(make_pair(2, 1));
        }
    }
}


void solve()
    {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            p1.push(aux);
        }
        ll x = n;
        

        for (int i = n; i > 0; i--)
        {

            ll valTop = p1.top();
            // cout << "Quero achar " << i  << endl;
            while (p1.size() > 0)
            {
                valTop = p1.top();

                if (valTop == i)
                    break;

                //cout << valTop << endl;

                if (p2.size() == 0)
                {
                    moves.push_back(make_pair(1, 2));

                    p2.push(valTop);
                    p1.pop();
                    continue;
                }

                valTop2 = p2.top();

                if (valTop2 > valTop)
                {
                    //cout << "Segunda pilha " << valTop2 << endl;

                    moves.push_back(make_pair(1, 2));
                    p2.push(valTop);
                    p1.pop();
                    continue;
                }

                valTop3 = p3.size() > 0 ? p3.top() : -1;

                if (valTop3 > valTop || valTop3 == -1)
                {
                    moves.push_back(make_pair(1, 3));
                    //cout << "Terceira pilha " << valTop3 << endl;

                    p1.pop();
                    p3.push(valTop);
                    continue;
                }
                unStack(i);

                p1.pop();
            }
            // cout << endl;
            if (p3.size() == 0 || p3.top() == i + 1){
                p1.pop();
                p3.push(i);
                moves.push_back(make_pair(1, 3));
                unStack(i- 1);
            }else{
                unStack(i);
                i = i + 1;
            }
        }

        cout << moves.size() << endl;
        for (auto [from, to] : moves)
        {
            cout << from << " " << to << endl;
        }
    }

    int main()
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout << setprecision(20) << fixed;
        int t = 1;
        if (multitest)
            cin >> t;
        while (t--)
        {
            solve();
        }
    }