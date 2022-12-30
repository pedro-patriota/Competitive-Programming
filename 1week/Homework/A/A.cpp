#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    map<set<int>, int> comb_map;
    multiset<int, greater<int>>best_comp;
    set< int> aux;
    
    int size = 1;
    int num_input, val;
    while (true)
    {
        cin >> num_input;
        if (num_input == 0)
        {
            break;
        }
        
        best_comp = multiset<int, greater<int>>();
        comb_map = map<set<int>, int>();
       
        for (int i = 0; i < num_input; i++)
        {
            int k = 0;
            aux = set<int>();
            bool is_similar = false;
            for (int j = 0; j < 5; j++)
            {
                cin >> val;
                aux.insert(val);
            }
            if (comb_map.count(aux)){
                best_comp.insert(++comb_map[aux]);
            }
            else{
                comb_map[aux] = 1;
                best_comp.insert(1);
            }
            if (*best_comp.begin() > num_input/2){
                break;
            }
            

        }
        auto it  = best_comp.begin();
        int res = *it;
        int counter = res;
        best_comp.erase(it);
        for (it = best_comp.begin(); it != best_comp.end(); ++it){
            if (*it != res){
                break;
            }else{
                counter += *it;
            }
        }
        cout << counter << "\n";

    }
}