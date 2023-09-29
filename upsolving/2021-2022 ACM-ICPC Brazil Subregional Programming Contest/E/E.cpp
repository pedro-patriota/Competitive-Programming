#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, t = 0, d = 0;
    cin >> n;
    map<int, stack<int>> enterTime;
    for (int i = 0; i < n; i ++){
        cin >> t >> d;
        enterTime[t].push(d);
        //enter.insert(t);
    }
    ii status = {-1, -1};
   
    auto it = enterTime.begin();
    while (it != enterTime.end()){
        int time = (*it).first;
        
        while ((*it).second.size() > 0){
            
            int dest = (*it).second.top();
            (*it).second.pop();
            if (status.X == -1 || time >= status.X + 10){
                status = {time, dest};
            }
            else if (status.Y == dest){
                status = {time, dest};
            }else{
                enterTime[status.X + 10].push(dest);
                
            }
        }
        it++;
        
    }
    cout << status.X + 10 << endl;

    

    
        
    return 0;
    
}