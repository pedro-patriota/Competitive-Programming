#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
int n;
vector<int> arr;
vector<int> pos;
vector<int> newPos;
vector<int> newArr;
vector<int> moves;

bool isPos = true;

void solve (int node){
    if (not isPos) return;
    int p = pos[node];
    if (p == newPos[node]) return;

    int nextPos, next;
    if (newPos[node] > p)   {
        nextPos = p + 1;
        next = arr[nextPos];
        while (newPos[next] > nextPos){
            solve(next); 
            if (not isPos) return;
            next = arr[nextPos];

        }
        if (abs(node -next) < 2){
            isPos = false; return;
        }
        pos[node] = nextPos;
        pos[next] = p;
        moves.push_back(p);
        swap(arr[nextPos], arr[p]);
        solve(node);
        

    }

}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr = pos = newPos= newArr = vector<int>(n + 1);
    for (int i  =1 ; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for (int i  =1 ; i <= n; i++){
        cin >> newArr[i];
        newPos[newArr[i]] = i;
    }

    for (int i = 1; i <= n; i++){
        solve(i);
        if (not isPos){
            cout << - 1 << endl;
            return 0;
        }
    }
    cout << moves.size() << endl;
    for (auto mv : moves){
        cout << mv << " ";
    }
        
    return 0;
    
}