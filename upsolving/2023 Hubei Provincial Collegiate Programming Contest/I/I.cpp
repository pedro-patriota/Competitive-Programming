#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define endl '\n'
map<ll, ll> primeF;
vector<ll> root;

ll fastModExp(ll x, ll y, ll m){
    ll ans = 1;
    x = x % m;      // Update 'x' if it is more than or equal to 'm'
    while(y){ // We walk through the bits of power "y"
        if(y & 1) ans = (ans*x) % m; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % m;
    }
    return ans;
}



ll lcm(ll a, ll b)
{
    ll aux = b / __gcd(a, b);
    //cout <<__gcd(a, b) << " " << aux << "*" <<a << endl;
    return a * aux ;
}

void primeFactors(ll n)
{
    primeF[2]++;
    //n = n/2;
    while (n % 2 == 0)
    {
        primeF[2]++;
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primeF[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        primeF[n]++;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, val, leastCM, x, y, lcm1 = 1, lcm2 = 1;
    cin >> n;
    ll half  = n/2;
    for (int i = 0; i < half; i++)
    {
        cin >> val;
        lcm1 = lcm(val, lcm1);
    }
    for (int i = half; i < n; i++){
        cin >> val;
        lcm2 = lcm(val, lcm2);
    }
    leastCM = lcm(lcm1, lcm2);
    //leastCM *= 2;
    primeFactors(leastCM);
    
    ll t = LLONG_MAX, z;
    //cout << leastCM << endl;
    vector<ll> sumArr;
    
    ll pos = 0;
    for (auto val : primeF){
        //cout << val.first << "-" << val.second << " ";
        sumArr.push_back(fastModExp(val.first,val.second, LLONG_MAX));
    }

    
    pos = 0;
    for (int mask =0; mask < (1 << sumArr.size()); mask++){
        ll a = 1;
        for (ll j = 0; j <  sumArr.size(); j++){
            if ((mask >> j) & 1){
                a = a * sumArr[j];
            }
        }
        ll b;
        if (a == 0){
            continue;
            b = leastCM;
        }else{
            double c = (double) leastCM/a;
            c += c;
            b = (ll) c;
            //cout << c << "/" << a << " ";
        }
        gcd(a, b, x, y);
        if (x == 0){
            t = min(t, abs(a -1));
            continue;
        }
        if (y == 0){
            t = min(t, abs(b -1));
            continue;
            
        }
        if (b*y + a*x == 1){
            
        if (x < 0){
            t = min(t, abs(x)*a);
        }else{
        }
            t = min(t, abs(y)*b);
        }

    }
    
    cout << t;
    return 0;
}