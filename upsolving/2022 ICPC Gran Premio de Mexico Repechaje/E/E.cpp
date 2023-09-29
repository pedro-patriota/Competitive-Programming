#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int ms = 212345;
vector<int> g[ms];
int idx[ms], low[ms], z, comp[ms], ncomp;
stack<int> st;
int dfs(int u) {
  if(~idx[u]) return idx[u] ? idx[u] : z;
  low[u] = idx[u] = z++;
  st.push(u);
  for(int v : g[u]) {
    low[u] = min(low[u], dfs(v));
  }
  if(low[u] == idx[u]) {
    while(st.top() != u) {
      int v = st.top();
      idx[v] = 0;
      low[v] = low[u];
      comp[v] = ncomp;
      st.pop();
    }
    idx[st.top()] = 0;
    st.pop();
    comp[u] = ncomp++;
  }
  return low[u];
}
bool solveSat(int n) {
  memset(idx, -1, sizeof idx);
  z = 1; ncomp = 0;
  for(int i = 0; i < 2*n; i++) dfs(i);
  for(int i = 0; i < 2*n; i++) if(comp[i] == comp[i^1]) return false;
  return true;
}
int trad(int v) { return v < 0 ?(~v)*2^1 : v * 2; }
void add(int a, int b) { g[trad(a)].push_back(trad(b)); }
void addOr(int a, int b) { add(~a, b); add(~b, a); }
void addImp(int a, int b) { addOr(~a, b); }
void addEqual(int a, int b) { addOr(a, ~b); addOr(~a, b); }
void addDiff(int a, int b) { addEqual(a, ~b); }

int n1, n2, c;
void bothAreZero(){
    addOr(~n1, ~n1);
    addOr(~n2, ~n2);
}
void bothAreOne(){
    addOr(n1, n1);
    addOr(n2, n2);
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, m;

    //SCC graph0, graph1, graph2;
    cin >> n >> m;
    //init(2*n);
    bool is_pos = true;

    for (int i = 0; i < m; i ++){
        string op;
        cin >> n1 >> n2 >> op >> c;

    
        
        if (not is_pos) continue;
        if (op == "="){
            if (c == 0){
                bothAreZero();
            }
            else if (c== 1){
                addOr(n1, n2);
                addOr(~n1, ~n2);

            }else if (c == 2){
                bothAreOne();
            }
        }else if(op == "!="){
            if (c == 0){
                addOr(n1, n2);
            }
            else if (c== 1){
               addEqual(n1, n2);
            }else if (c == 2){
                addOr(~n1, ~n2);
            }

        }else if (op == "<"){
            if (c == 0){
                is_pos = false;
            }
            else if (c== 1){
                bothAreZero();

            }else if (c == 2){
                addOr(~n1, ~n2);
            }
            
        }else if (op == ">"){
            if (c == 0){
                addOr(n1, n2);
            }
            else if (c== 1){
                bothAreOne();
            }else if (c == 2){
                is_pos = false;

            }
            
        }else if (op == "<="){
            if (c == 0){
                bothAreZero();
            }
            else if (c== 1){
                addOr(~n1, ~n2);
            }else if (c == 2){
                /* addOr(n1, ~n1);
                addOr(n2, ~n2); // true */

            }
           
            
        }else if (op == ">="){
            if (c == 0){
                /* addOr(n1, ~n1);
                addOr(n2, ~n2); // true */
            }
            else if (c== 1){
                addOr(n1, n2);
                            
            }else if (c == 2){
                bothAreOne();
            }
        }

    }
    if (not is_pos) {
        cout << "No" << endl;
        return 0;
    }

    is_pos = solveSat(n);

    if (not is_pos) {
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
        
    return 0;
    
}