#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define X first
#define Y second

vector<pii> wines;
vector<pii> motoBikes;
vector<pii> distsWine;
int n, m;
ll ans = 0;

pii restaurant;

int distance(pii a, pii b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void FirstMove()
{
    pair<int, pii>  bestAdvantage = {-INT_MAX, {-1, -1}};
    bool hasBikeOnRestaurant = false;
    for (auto [motoX, motoY] : motoBikes)
    {
        if (motoX == restaurant.X && motoY == restaurant.Y)
        {
            hasBikeOnRestaurant = true;
            return;
        }
    }
    int dist;
    for (int j = 0; j < m ; j++)
    {
        for (int i = 0; i < n; i++)
        {
            dist = distance(wines[i], motoBikes[j]) + distsWine[i].X; 
            int advantage  =  2*distsWine[i].X - dist;
            if (advantage > bestAdvantage.X) {
                bestAdvantage.X = advantage;
                bestAdvantage.Y = {j, i};
            }
        }
    }
    int bikeToMove = bestAdvantage.Y.X;
    int wineToMove = bestAdvantage.Y.Y;
    dist = distance(wines[wineToMove], motoBikes[bikeToMove]) + distsWine[wineToMove].X; 
    
    motoBikes[bikeToMove] = restaurant;
    ans += dist;
    distsWine[wineToMove].first = 0;

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        wines.push_back({x, y});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        motoBikes.push_back({x, y});
    }
    cin >> x >> y;
    restaurant = {x, y};

    for (int i = 0; i < n; i++)
    {
        int dist = distance(wines[i], restaurant);
        distsWine.push_back({dist, i});
    
    }
    FirstMove();

    sort(distsWine.begin(), distsWine.end());

    for (int i = n - 1; i >= 0; i--)
    {
        int dist = distsWine[i].first;
        auto wine = wines[distsWine[i].second];
        if (dist == 0)
            continue;
        pii minDist = {INT_MAX, -1};
        int moto = 0;
        for (auto [motoX, motoY] : motoBikes)
        {
            int distWineMoto = distance(wine, {motoX, motoY});
            if (distWineMoto < minDist.X)
            {
                minDist.X = distWineMoto;
                minDist.Y = moto;
            }
            moto++;
        }

        motoBikes[minDist.Y] = {0, 0};
        ans += dist + minDist.X;
    }

    cout << ans << endl;

    return 0;
}