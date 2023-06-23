#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string X, Y;
    cin >> X >> Y;
    map<string, double> compass;
    compass["N"] = 0;
    compass["S"] = 180;
    compass["E"] = 90;
    compass["W"] = 270;
    compass["NW"] = 315;
    compass["SW"] = 225;
    compass["SE"] = 135;
    compass["NE"] = 45;

    string letter = "", next_letter = "", first = "", second = "";
    if (X.size() > 2)
    {
        first += X[X.size() - 2];
        second += X[X.size() - 1];
        letter += X[X.size() - 2];
        letter += X[X.size() - 1];
        if (letter[0] == 'N')
        {
            if (letter[1] == 'W')
            {
                compass["N"] = 360;
            }
        }
        for (int i = X.size() - 3; i >= 0; i--)
        {
            next_letter += X[i];
            compass[next_letter + letter] = (compass[letter] + compass[next_letter]) / 2;
            if (next_letter == first)
            {
                compass[second] = compass[letter];
            }
            else
            {
                compass[first] = compass[letter];
            }
            letter = next_letter + letter;
            next_letter = "";
        }
    }
    double ang1 = compass[X];
    first = second = letter = "";
    compass = map<string, double>();
    compass["N"] = 0;
    compass["S"] = 180;
    compass["E"] = 90;
    compass["W"] = 270;
    compass["NW"] = 315;
    compass["SW"] = 225;
    compass["SE"] = 135;
    compass["NE"] = 45;
    if (Y.size() > 2)
    {
        first += Y[Y.size() - 2];
        second += Y[Y.size() - 1];
        letter += first;
        letter += second;
        if (letter[0] == 'N')
        {
            if (letter[1] == 'W')
            {
                compass["N"] = 360;
            }
        }
        for (int i = Y.size() - 3; i >= 0; i--)
        {
            next_letter += Y[i];
            compass[next_letter + letter] = (compass[letter] + compass[next_letter]) / 2;
            if (next_letter == first)
            {
                compass[second] = compass[letter];
            }
            else
            {
                compass[first] = compass[letter];
            }
            letter = next_letter + letter;
            next_letter = "";
        }
    }

    double ang2 = compass[Y];
    double dist = abs(ang1 - ang2);
    cout << setprecision(20) << min(dist, 360 - dist);

    return 0;
}