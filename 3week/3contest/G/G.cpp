#include <bits/stdc++.h>
using namespace std;
long long num_guilty, claw_dist, alive, claw;
vector<long long> claws;
vector<long long> dead_alive;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_guilty;
    dead_alive = vector<long long>(num_guilty, 1);
    alive = num_guilty;

    for (long long i = 0; i < num_guilty; i++){
        cin >> claw_dist;
        claws.push_back(claw_dist);
    }
    /* for (long long i = num_guilty -1; i >= 0; i--){
        claw = claws[i];
        if (claw > i -1){
            alive -= i -1;
            break;
        }
        alive -= claw;
        for (long long j = i-1; j >= i - claw; j--){
            if (j - claws[j] > i - claw){
                i = j;

            }
        }
    } */
    
}