#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll t, w, h, l, x1, y1, z1, x2, y2, z2, n;
    ll total_v = 0, temp_v = 0;
    cin >> t;
    while (t != 0)
    {
        t--;
        cin >> w >> h >> l;
        total_v = w * h;
        ll tempL = 0, rest = 0;
        bool is_pos = true;
        cin >> n;
       
        for (ll i = 0; i < n; i++)
        {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
         

            temp_v = (x2-x1)*(y2-y1);
            double aux = (double) total_v/(z2-z1);
            if (temp_v >= aux){
                ll division =  (ll) temp_v/aux;
                tempL += division;
                rest += (ll) (((double) temp_v/aux - (double) division)*total_v);
            }
            else{
                rest += temp_v*(z2- z1);
            }
            tempL += rest/total_v;   
            rest = rest%total_v;
        }
        
        if (rest != 0 ||  tempL != l){
            //cout << rest << " " << tempL;
            cout << "No" << endl;
            continue;
        }

        
        



        
    }

    return 0;
}