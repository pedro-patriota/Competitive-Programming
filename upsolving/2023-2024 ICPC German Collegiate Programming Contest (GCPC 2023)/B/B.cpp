#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int ms = 2e4 + 17;
bool visited[ms];

int visits = 0, begins = 0;
int n;

struct PT {
	typedef long long T;
	T x, y;
	PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	//PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	//double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }

	friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};

struct Segment {
	typedef long double T;
	PT p1, p2;
	T a, b, c;

	Segment() {}

	Segment(PT st, PT en) {
		p1 = st, p2 = en;
		a = -(st.y - en.y);
		b = st.x - en.x;
		c = a * en.x + b * en.y;
	}

	T plug(T x, T y) {
		// plug >= 0 is to the right
		return a * x + b * y - c;
	}

	T plug(PT p) {
		return plug(p.x, p.y);
	}

	bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
	bool inSegment(PT p) {
		return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
	}

	PT lineIntersection(Segment s) {
		long double A = a, B = b, C = c;
		long double D = s.a, E = s.b, F = s.c;
		long double x = (long double) C * E - (long double) B * F;
		long double y = (long double) A * F - (long double) C * D;
		long double tmp = (long double) A * E - (long double) B * D;
		x /= tmp;
		y /= tmp;
		return PT(x, y);
	}
	
	
};

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if (n <= 6)
    {
        cout << "possible" << endl;
        return 0;
    }

    vector<PT> points (n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        points[i] = PT(x, y);
    }
    vector<Segment> firstLine;
    firstLine.push_back(Segment(points[0], points[1]));
    firstLine.push_back(Segment(points[0], points[2]));
    firstLine.push_back(Segment(points[0], points[3]));
    firstLine.push_back(Segment(points[1], points[2]));
    firstLine.push_back(Segment(points[1], points[3]));
    firstLine.push_back(Segment(points[2], points[3]));
    

    for (auto line1 : firstLine)
    {
        vector<PT> secondPoints;
        vector<Segment> secondLine;
        for (int i = 0; i < n; i++)
        {
            if (secondPoints.size() == 3) break;
            if (not line1.inLine(points[i])){
                secondPoints.push_back(points[i]);
            }
        }
        if (secondPoints.size() < 3) {cout << "possible" << endl; return 0;}
        secondLine.push_back(Segment(secondPoints[0], secondPoints[1])); 
        secondLine.push_back(Segment(secondPoints[0], secondPoints[2])); 
        secondLine.push_back(Segment(secondPoints[1], secondPoints[2]));

        for (auto line2 : secondLine){

            vector<PT> thirdPoints;
            Segment line3;
            for (int i  = 0; i < n; i++){
                if (thirdPoints.size() == 2) break;
                if (not line1.inLine(points[i]) && not line2.inLine(points[i])){
                    thirdPoints.push_back(points[i]);
                }
            } 
            if (thirdPoints.size() < 2)  {cout << "possible" << endl; return 0;}
            line3 = Segment(thirdPoints[0], thirdPoints[1]);

            bool isPos = true;
            for (int i = 0;  i < n; i++){
                if (not line1.inLine(points[i]) && not line2.inLine(points[i]) && not line3.inLine(points[i])) {
                    isPos = false;
                    break;
                }
            }
            if (isPos)  {
                cout << "possible" << endl; return 0;
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}