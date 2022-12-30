#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int cd_num_jack, cd_num_jill, cd_id;
    map<int, int, greater<int>> freq_map;
    while (true)
    {   
        cin >> cd_num_jack;
        cin >> cd_num_jill;
        int counter = 0;
        if (cd_num_jack == 0 && cd_num_jill == 0){
            break;
        }
        for (int i = 0; i < cd_num_jack; i ++){
            cin >> cd_id;
            freq_map[cd_id]++;
        }   
        for (int i = 0; i < cd_num_jill; i ++){
            cin >> cd_id;
            freq_map[cd_id]++;

        }
        for (auto it : freq_map){
            if (it.second > 1){
                counter ++;
            }
            else if (it.second == 1){
                break;
            }
        }
        cout << counter << "\n";
        freq_map =map<int, int, greater<int>>();
    }
    
}