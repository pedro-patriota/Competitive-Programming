#include <bits/stdc++.h>
using namespace std;
long max_pos;
long num_stalls, num_cows;
vector<long>stalls;

bool is_possible(long m){
    long act_stall = 0;

    for (long i = 0; i < num_cows - 1; i++){
        long next_stall = act_stall + 1;
        while(next_stall < num_stalls && (stalls[next_stall] - stalls[act_stall]) < m){
            next_stall++;
        }
        if (next_stall == num_stalls){
            return false;
        }
        act_stall = next_stall;

    }
    return true;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long test_cases;
    cin >> test_cases;
    for (long i = 0; i < test_cases; i++){
        long stall, maxim = LONG_MIN, mini = LONG_MAX;
        cin >> num_stalls;
        cin >> num_cows;
        for (long j = 0; j < num_stalls; j++){
            cin >> stall;
            if (stall > maxim){
                maxim = stall;
            }
            if (stall < mini){
                mini= stall;
            }
            stalls.push_back(stall);
        }
        max_pos = maxim - mini;
        sort(stalls.begin(), stalls.end());
        long l = 0, m = max_pos, r = max_pos;
        while(l < r){
            m = (l+r+1)/2;
            if (is_possible(m)){
                l = m;
            }
            else{
                r = m - 1;
            }
        }
        stalls = vector<long>();
        cout << l << "\n";
        
    }

    
}