#include <bits/stdc++.h>
using namespace std;
long long num_nodes, num_edges, test_cases, node1, node2;
vector<deque<long long>> adj;
vector<long long>colour;

void dfs (long long u){
    for (auto val : adj[u]){
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

    while (true){
        cin >> num_nodes;
        if (num_nodes == 0){
            break;
        }
        cin >> num_edges;
        adj = vector<deque<long long>> (num_nodes);
        colour = vector<long long>(num_nodes, -1);
        bool is_possible = true;
        for (long long edge = 0; edge < num_edges; edge++){
            cin >> node1 >> node2;

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        for (long long i = 0; i < num_edges; i++){
            if (colour[i] == -1){
                colour[i] = 1;
                dfs(i);
            }
        }
        for (long long i = 0; i < num_edges; i++){
            for (auto val : adj[i]){
                if (colour[val] == colour[i]){
                    is_possible = false;
                    break;
                }
            }
        }
        if (is_possible){
            cout << "BICOLORABLE.\n";
        }else{
            cout << "NOT BICOLORABLE.\n";
        }
    }   
    
}