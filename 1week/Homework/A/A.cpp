#include <bits/stdc++.h>

using namespace std;
class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    }
};

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    vector<unordered_set<int>> comb_map(1);
    vector<int> freq_map (1, 1);
    multiset<int, greater<int>>best_comp;

    unordered_set< int> aux;
    priority_queue<int>a;
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
        best_comp.insert(1);

        for (int j = 0; j < 5; j++)
        {
            cin >> val;
            comb_map[0].insert(val);
        }

        for (int i = 1; i < num_input; i++)
        {
            int k = 0;
            aux = unordered_set<int>();
            bool is_similar = false;
            for (int j = 0; j < 5; j++)
            {
                cin >> val;
                aux.insert(val);
            }
            for (int j = 0; j < size; j++)
            {
                if (aux == comb_map[j]){
                    freq_map[j]++;
                    best_comp.insert(freq_map[j]);
                    is_similar = true;
                    break;   
                }
            }
            if (!is_similar){
                comb_map.push_back(aux);
                freq_map.push_back(1);
                best_comp.insert(1);
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