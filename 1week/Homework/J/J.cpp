#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int num_show, tvs = 2, begin, end;
    multimap<int, int> channel_map;
    multiset<int> ongoing;
    ongoing.insert(-1);
    ongoing.insert(-1);

    bool is_possible = true;
    cin >> num_show;
    for (int i = 0; i < num_show; i++)
    {
        cin >> begin;
        cin >> end;
        channel_map.insert(make_pair(begin, end));
    }
    for (auto it : channel_map)
    {
        if (it.first > *ongoing.begin()){
            ongoing.erase(ongoing.begin());
            ongoing.insert(it.second);
            continue;
        }

        is_possible = false;
        break;
        
        
    }
    if (is_possible){
        cout << "YES";
    }else{
        cout << "NO";
    }
}