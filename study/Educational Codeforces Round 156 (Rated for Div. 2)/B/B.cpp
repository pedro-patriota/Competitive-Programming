#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define dd pair<double, double>
#define X first
#define Y second

const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);
int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}
struct Point{
	double x,y;
	Point(double x = 0, double y = 0) : x(x),y(y){}
	Point(const Point& p): x(p.x), y(p.y){}
  bool operator < (const Point &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator == (const Point &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
  bool operator != (const Point &p) const {return !(p == *this);}

	// basic ops
	Point operator + (const Point& p) const {return Point(x+p.x,y+p.y);}
	Point operator - (const Point& p) const {return Point(x-p.x,y-p.y);}
	Point operator * (const double k) const {return Point(x*k,y*k);}
	Point operator / (const double k) const {return Point(x/k,y/k);}
};
	// points ops
double dot (const Point& p,const Point& q) { return p.x*q.x + p.y*q.y; }
double cross (const Point& p,const Point& q) { return p.x*q.y - p.y*q.x; }
double norm(const Point& p) { return hypot(p.x,p.y); }
double dist(const Point& p, const Point& q) { return hypot(p.x-q.x,p.y-q.y); }
double dist2(const Point& p, const Point& q) { return dot(p-q,p-q); }
Point normalize(const Point &p) { return p/hypot(p.x, p.y); }
double angle (const Point& p, Point& q) { return atan2(cross(p, q), dot(p, q)); }
double angle (const Point& p) { return atan2(p.y, p.x); }


bool multiTest = true;
Point o, p, b, a;



bool isPos (double m){
    auto dAO = dist(a, o);
    auto dAP = dist(a, p);
    auto dBO = dist(b, o);
    auto dBP = dist(b, p);
    auto dAB = dist(a, b);
    if (dAO <= m && dAP <= m){
        return true;
    }
    if (dBO <= m && dBP <= m){
        return true;
    }
    if ((dAO <= m || dBO <= m) && (dAP <= m || dBP <= m)){
        if (dAB <= 2*m){
            return true;
        }
    }
    return false;



}   

void solve(){
    o = {0, 0};
    double x, y;
    cin >> x >> y;
    p = {x, y};
    cin >> x >> y;
    a = {x, y};
    cin >> x >> y;
    b = {x, y};

    double l, m, r;
    l = 0;
    r = 1e4 + 17;
    while (r - l > 1e-6){
        m = (l + r)/2;  
        if (isPos(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << l << endl;
}

int main()
{
    ios ::sync_with_stdio();
    cin.tie(0);
    cout << setprecision(12) << fixed;
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}