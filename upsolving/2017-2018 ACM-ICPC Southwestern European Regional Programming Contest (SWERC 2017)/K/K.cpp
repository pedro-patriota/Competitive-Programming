    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define endl '\n'

    const double inf = 1e100, eps = 1e-12;
    const double PI = acos(-1.0L);

    // Note: Whenever possible, work only with integers!
    // If integers are used, the "cmp" function will no longer work.
    // It's necessary to remove it from all locations!
    int cmp(double a, double b = 0){
        if(abs(a-b) < eps) return 0;
        return (a < b) ? -1 : +1;
    }

    // Struct to represent a point/vector
    struct PT{
        double x, y;
        PT(double x = 0, double y = 0) : x(x), y(y) {}
        PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
        PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
        PT operator * (double c) const { return PT(x*c, y*c); }
        PT operator / (double c) const { return PT(x/c, y/c); }
        bool operator < (const PT &p) const {
            if(cmp(x, p.x) != 0) return x < p.x;
            return cmp(y, p.y) < 0;
        }
        bool operator == (const PT &p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
        bool operator != (const PT &p) const { return !(p == *this); }
    };

    // Debug function
    ostream &operator << (ostream &os, const PT &p){
        return os << "(" << p.x << "," << p.y << ")";
    }

    // Function to calculate the dot product (u.v)
    double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }

    // Function to calculate the cross product (uXv) (2x2 determinant)
    double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

    // Function to calculate the magnitude of the vector (|u|)
    double norm (PT p) { return hypot(p.x, p.y); }

    // Function to calculate the distance of 2 points
    double dist (PT p, PT q) { return hypot(p.x - q.x, p.y - q.y); }

    vector<PT> convexHull(vector<PT> p, bool needSort = 1){
        if(needSort) sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        int n = p.size(), k = 0;
        if(n <= 1) return p;
        vector<PT> answ(2*n + 1);   // Must be 2*n + 1 for collinear points

        // Lower hull
        for(int i = 0; i < n; i++){
            while(k >= 2 && cross(answ[k - 1] - answ[k - 2], p[i] - answ[k - 2]) < 0) k--; // If collinear points are allowed put only "<"
            answ[k++] = p[i];
        }

        // Upper hull
        for(int i = n - 2, t = k + 1; i >= 0; i--) {
            while(k >= t && cross(answ[k - 1] - answ[k - 2], p[i] - answ[k - 2]) < 0) k--; // If collinear points are allowed put only "<"
            answ[k++] = p[i];
        }

        answ.resize(k); // n+1 points where the first is equal to the last
        return answ;
    }

    PT projPtLine (PT a, PT b, PT c) { // ponto c na linha a - b, a.b = |a| cost * |b|
        return a + (b-a) * dot(b-a, c-a)/dot(b-a, b-a);
    }
    // Function to project point c onto segment a - b
    /* PT projPtInSegment(PT a, PT b, PT c){
        double r = dot(b - a, b - a);
        if(cmp(r) == 0) return a;
        r = dot(b - a, c - a) / r;
        if(cmp(r, 0) < 0) return a;
        if(cmp(r, 1) > 0) return b;
        return a + (b - a) * r;
    } */
    // Function to calculate the minimum distance between point c and segment a-b
    double distPtSegment(PT a, PT b, PT c){
        return dist(c, projPtLine(a, b, c));
    }


    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);

        int points;
        ll x, y, radius;
        cin >> points >> radius;
        vector<PT> arrP(points);

        cout << fixed <<setprecision(20);
        for (int i = 0 ; i < points; i++){
            cin >> x >> y;
            arrP[i] = PT(x, y);
        }
        vector<PT> hull = convexHull(arrP, 1);
        int sz = hull.size();
        
        sz--;

        PT p1, p2, p3;
        p1 = hull[0];
        p2 = hull[1];
        double maxDist = -1;
        int pt = -1;
        for (int i = 2; i < sz; i++){
            auto dist = distPtSegment(p1, p2, hull[i]);
            if (maxDist < dist) {
                maxDist = dist; pt = i;
            }   
        }
        
        double minDist = maxDist;
        for (int i = 1; i < sz; i++){
            p1 = hull[i];
            p2 = hull[(i + 1)%sz];

            while (distPtSegment(p1, p2, hull[(pt + 1)% sz]) > distPtSegment(p1, p2, hull[pt])){
                maxDist = distPtSegment(p1, p2, hull[(pt + 1)% sz]);
                pt = ((pt + 1)% sz);
            }
            minDist = min(minDist, maxDist);

        }

        cout << minDist;

        
        
            
        return 0;
        
    }