#include <bits/stdc++.h>
using namespace std;
long long num_scenarios, num_bugs, num_it, bug1, bug2;
vector<deque<long long> >pos_comb;
vector<vector<bool>> conect;
vector<long long> colour;
void dfs(long long u){
    for (auto val : pos_comb[u]){
        if (colour[val] == -1){
            colour[val] = 1 - colour[u];
            dfs(val);
        }
    }
}   

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_scenarios;
    for (long long i = 0; i < num_scenarios; i++){
        cin >> num_bugs >> num_it;
        pos_comb = vector<deque<long long>> (num_bugs);
        colour = vector<long long> (num_bugs, -1);
        conect = vector<vector<bool>> (num_bugs, vector<bool>(num_bugs, false));
        for (long long it = 0; it < num_it; it++){
            cin >> bug1 >> bug2;
            bug1--;
            bug2--;
            if (conect[bug1][bug2] == false){
                conect[bug1][bug2] = true;
                conect[bug2][bug1] = true;

                pos_comb[bug1].push_back(bug2);
                pos_comb[bug2].push_back(bug1);
            }
        }
        for (long long i = 0; i < num_bugs; i++){
            if (colour[i] == -1){
                colour[i] = 1;
                dfs(i);
            }
        }
        bool sus = false;
        for (long long i = 0; i < num_bugs; i++){
            for (auto val : pos_comb[i]){
                if (colour[i] == colour[val]){
                    sus = true;
                    break;
                }
            }
        }
         

        cout << "Scenario #" << i + 1 << ":\n";
        if (sus){
            cout << "Suspicious bugs found!\n";
        }else{
            cout << "No suspicious bugs found!\n";

        }
    }
    
    
}