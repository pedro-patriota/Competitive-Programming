#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define PI 3.141592654

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int num_points, x, y, best_point = -1;
    cin >> num_points;
    vector<pair<double, double>> points(num_points);
    for (ll i = 0; i < num_points; i++)
    {
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }
    double ang_sea, ang_point, ang_to_point, maxAng_left, maxAng_right;
    for (ll i = 1; i < num_points; i++) // looking for the left point of the island
    {
        double tan = ((points[i].second) / (points[i].first - points[0].first));
        ang_sea = atan(tan);
        ang_sea = ang_sea * 180 / PI;

        if (best_point == -1)
        {
            best_point = i;
            ang_point = ang_sea;
            continue;
        }

        if (points[i].second <= points[best_point].second)
        {
            continue;
        }

        tan = ((points[i].second - points[best_point].second) / (points[i].first - points[best_point].first));
        ang_to_point = atan(tan);
        ang_to_point = ang_to_point * 180 / PI;

        if (ang_to_point > ang_point)
        {
            best_point = i;
            ang_point = ang_sea;
            continue;
        }
    }
    maxAng_left = ang_point;
    best_point = -1;
    for (ll i = num_points - 2 ; i >= 0; i--) // looking to the righest point in the island 
    {
        double tan = ((points[i].second) / (points[num_points -1].first - points[i].first));
        ang_sea = atan(tan);
        ang_sea = ang_sea * 180 / PI;

        if (best_point == -1)
        {
            best_point = i;
            ang_point = ang_sea;
            continue;
        }

        if (points[i].second <= points[best_point].second)
        {
            continue;
        }

        tan = (( points[i].second - points[best_point].second) / (-points[i].first + points[best_point].first));
        ang_to_point = atan(tan);
        ang_to_point = ang_to_point * 180 / PI;

        if (ang_to_point > ang_point)
        {
            best_point = i;
            ang_point = ang_sea;
            continue;
        }
    }
    maxAng_right = ang_point;

    cout << setprecision(12) << max(maxAng_left, maxAng_right);
    return 0;
}