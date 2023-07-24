#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<double> arr(4);

bool valid(double x, double y, double z){
	return x < y + z && y < x + z && z < x + y;
}

double herons(double a, double b, double c)
{
    double semi = (double)(a + b + c) / 2;
    double ans = (double)semi * (semi - a) * (semi - b) * (semi - c);
    // cout << "semi :" << semi << " ans :" << ans << endl;
    if (ans < 0 && valid (a, b, c))
        return -1;
    return (double)sqrt(ans);
}

double a, b, c, d, a1, b1, c1, d1, maxA;

double f(double m)
{
    double A = 0, A1, A2, x;
    x = (double) sqrt(a*a + b*b - 2*a*b*cos(m));
    A1 = herons(a, b, x);
    if (A1 < 0)
        return -1;
    A2 = herons(c, d, x);
    // cout << "A1 " << A1 << " A2 " << A2 << endl;
    if (A2 < 0)
        return -1;
    
    A = A1 + A2;
    
    //cout << " a " << a1 << " b: " << b1 << " c: " << c1 << " d: " << d1 << endl;
    return A;
}

double ternary_search(double l, double r)
{
    double eps = 1e-9; // set the error limit here
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); // evaluates the function at m1
        double f2 = f(m2); // evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }

    return f(l); // return the maximum of f(x) in [l, r]
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3];
    maxA = max(maxA, ternary_search(0, acos(-1)));
    a = arr[0]; b = arr[2]; c = arr[1]; d = arr[3];
    maxA = max(maxA, ternary_search(0, acos(-1)));
    a = arr[0]; b = arr[3]; c = arr[1]; d = arr[2];
    maxA = max(maxA, ternary_search(0, acos(-1)));

    cout << maxA;

    return 0;
}