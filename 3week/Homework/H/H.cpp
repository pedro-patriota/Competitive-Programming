#include <bits/stdc++.h>
using namespace std;
vector<deque<long long>> adj;
vector<char> table;
vector<bool> visited;
long long test_cases, height, width, source, counter;
void dfs (long long u){
    for (auto val : adj[u]){
        if (not visited[val]){
            visited[val] = true;
            counter++;
            dfs(val);
        }
    }
}
int main()
{

    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_cases;
    for (long long test = 0; test < test_cases; test++)
    {
        cin >> width >> height;
        table = vector<char>(width * height);
        visited = vector<bool>(width * height, false);
        counter = source = 0; 
        adj = vector<deque<long long>>(width * height);
        for (long long i = 0; i < height; i++)
        {
            for (long long j = 0; j < width; j++)
            {
                cin >> table[i * width + j];
                if (table[i * width + j] != '#')
                {
                    if (table[i * width + j] == '@')
                    {
                        source = i * width + j;
                    }
                    if (j > 0)
                    {
                        if (table[i * width + (j - 1)] != '#')
                        {
                            adj[i * width + j].push_back(i * width + (j - 1));
                            adj[i * width + (j - 1)].push_back(i * width + j);
                        }
                    }
                    if (i > 0)
                    {
                        if (table[(i - 1) * width + j] != '#')
                        {
                            adj[i * width + j].push_back((i - 1) * width + j);
                            adj[(i - 1) * width + j].push_back(i * width + j);
                        }
                    }
                }
            }
        }
        visited[source] = true;
        counter++;
        dfs(source);
        cout << "Case " << test + 1 << ": " << counter << "\n";



    }
}