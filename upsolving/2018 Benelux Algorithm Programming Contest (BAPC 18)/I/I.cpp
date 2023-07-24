#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, ll>
int n, m, s;
ll maxTime;
vector<ll> people;
vector<int> locationToShelter;
vector<vector<pair<int, ll>>> adjv;
map<int, ll> shelter;
map<int, int> shelterToIndex;
vector<ll> timeArr;

const int mS = 11;
const int maxShelter = 10;

ll dis[maxShelter][mS];
ll newDis[maxShelter][(1<<maxShelter) + maxShelter + 17];

void dijkstra(int shelter, int x) {
  for (int j = 0; j < mS; j++){
    dis[shelter][j] = LLONG_MAX;
  }
  dis[shelter][x] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0, x));
  while(!pq.empty()) {
    ii x = pq.top(); pq.pop();

    locationToShelter[x.second] += (1 << shelter);

    int u = x.second;
    if(x.first > dis[shelter][u]) continue;
    for(auto e : adjv[u]) {
      int v = e.first, w = e.second;
      if(dis[shelter][u]+w < dis[shelter][v]) {

        dis[shelter][v] = dis[shelter][u] + w;
        pq.push(ii(dis[shelter][v], v));
      }
    }
  }
}

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    people = vector<ll> (n+1);
    locationToShelter = vector<int> (n+1, 0);

    for (int i = 0; i < n; i++) cin >> people[i+1];
    


    adjv = vector<vector<pair<int, ll>>> (n+1);
    for (int i  = 0; i < m ; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        

        adjv[u].push_back(make_pair(v, w));
        adjv[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= s; i ++) {
        int v;
        ll capacity;
        cin >> v >> capacity;
        shelterToIndex[v] = i;
        dijkstra(i, v);
        
        shelter[i] = capacity;
    }

    map<int, vector<int>> groupSameNeighbours;
    for (int i = 1; i <= n; i++){
        int bitmask = locationToShelter[i];
        groupSameNeighbours[bitmask].push_back(i);
    }
    int newIndexLocation = s + 1;
    int sink = s + 1 + groupSameNeighbours.size();
    Dinic dinic(sink + 1)
    for (int i = 1 ; i <= s; i ++){
        add(0, i, shelter[i]);
    }
    ll totalPeople = 0;
    timeArr = vector<ll> (s + groupSameNeighbours.size() + 17);
    for (auto [bitmask, locations] : groupSameNeighbours){
        ll qntPeople = 0;
        //vector<ll> totalTime(s, 0);
        for (auto location : locations){
            qntPeople += people[location];
            
            for (int i = 0; i < s; i++){
                bool bit  = bitmask & (1<<i);
                if (bit){
                    newDis[i][newIndexLocation] += dis[i][location];
                }
            }

        }

        for (int i = 1; i <= s; i++){
            bool bit  = bitmask & (1<<i);
            if (bit){
                add(i, newIndexLocation, 1e5 + 17);
            }
        }
        add(newIndexLocation,sink, qntPeople);

        totalPeople += qntPeople;
        newIndexLocation++;
    }

    ll l = 0, r = LLONG_MAX;
    while (l < r){
        maxTime = (l+r)/2;
        if (maxflow(0, sink) >= totalPeople){
            r = m;
        }else{
            l = m + 1;
        }
    }
    cout << l;


 

    return 0;
    
}