#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    vector<iii> allQ;
    cin >> n >> k;

    vector<queue<ii>> qs (k + 1);
    for (int i = 0;  i < 2*n; i++){
        int op, person, q;
        cin >> op;
        
        if (op == 1){
            cin >> person >> q;
            qs[q].push({person, i});
        }else{
            cin >> q;
            auto [person, entry] = qs[q].front();
            qs[q].pop();
            int leave;
            leave = i;
            //q = get<2> (people[person]);

            allQ.push_back({entry, leave, person});
        }
    }
    for (auto q : qs){
        while (q.size() > 0){
            auto [person, entry] = q.front();
            q.pop();

            allQ.push_back({entry, 1e6, person});
            
        }
    }
    sort(allQ.begin(), allQ.end());

    ii prev = {-1, -1};
    vector<int> sad;
    set<ii, greater<ii>> out;
    for (auto [entry, leave, person] : allQ){
        while (leave < (*out.begin()).first && not out.empty()){
            int otherPerson = (*out.begin()).second;
            sad.push_back(otherPerson);
            out.erase(out.begin());

        }
        out.insert({leave, person});
    }
    sort(sad.begin(), sad.end());
    cout << sad.size() << endl;
    for (auto p : sad){
        cout << p << " ";
    }

    
    
        
    return 0;
    
}