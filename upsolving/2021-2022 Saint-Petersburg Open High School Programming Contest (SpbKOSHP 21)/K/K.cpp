#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    double X, T, temp, best, l, r, m, slopeL, slopeR, left, right;
    cin >> X >> T;
    best = (double)(2*T / 3)*100;
    best = max(best, (double) (5*T/6)*X);
    l = 0;
    r = T / 6;
    slopeL = (X * 6) / T;
    slopeR = (((100 - X) * 6) / T);
    right = ((r + T / 3) / 2);
    double auxR = (T - right) * ((( -T/6 + right)*slopeR) + X);

    left  = ((l + r)/2);
    double auxL = (T - left)*(left*slopeL);

    if (auxR > auxL){
        l = r;
        r = T/3;

        while (abs(l -r) > 1e-7){
            m = (l + r)/2;
            left = (l + m)/2;
            right = (r + m)/2;
            if (( ((left  - T/6)*slopeR) + X)*(T-left) > (((right  - T/6)*slopeR) + X)*(T-right)){
                temp = (((left  - T/6)*slopeR) + X)*(T-left);
                r = m;
            }else{
                temp =(((right  - T/6)*slopeR) + X)*(T-right);
                l = m;
            }
        }
        best = max(best, temp);
    }
    else{
        
        while (abs(l -r) > 1e-7){
            m = (l + r)/2;
            left = (l + m)/2;
            right = (r + m)/2;
            if ((T- left)*(left*slopeL) > (T-right)*(right*slopeL)){
                temp = (T- left)*(left*slopeL);
                r = m;
            }else{
                temp =(T-right)*(right*slopeL);
                l = m;
            }
        }
        best = max(best, temp);
    }
    cout << setprecision(12) << best;

    return 0;
}