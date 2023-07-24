#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll c, n, point;
vector<ll> points;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> n;
    points = vector<ll> (c);
    vector<ll> prefix (2*c + 2);

    ll left = 0, right, dist = 1e9;
    ll past = 0, first = 0;
    for (ll i = 0; i < n; i++){
        cin >> point;
        if (not first) {first = point ; past = point; continue;}

        points[point] = 1;
        if (point - past < dist){
            dist = point - past;
            right = point;
            left = past;
        }
        past = point; 
    }
    if (abs(point - first) < dist){
        dist = abs(point - first);
        right = point;
        left = left;
    }

    prefix[0] = 0;
    for (ll i = 0; i < 2*c; i++){
        prefix[i+1] = prefix[i] + points[i%c];
    }

    double step = (double) dist/1e4;

    bool is_pos = true;
    for (double actPoint = (double) left + step; actPoint <   (double) right; actPoint +=  (double) step){
        is_pos = true;
        for (int part  = 1; part < n; part++){
            double nextPoint = fmod((actPoint + ((c/n) *part)), c);
            ll l = floor(actPoint) + 1;
            ll r = floor(nextPoint) + 1;
            if (actPoint + ((c/n) *part) > c){
                r += c;
            }
            //cout << nextPoint << " " << actPoint << " " <<  part << endl;
            if (prefix[r] - prefix[l] != 1){
                is_pos = false;
                break;
            }

        }
        if (is_pos) break;
    }
    if (is_pos){
        cout << 'S';
    }else{
        cout << 'N';
    }
    cout << endl;




    
        
    return 0;
    
}