#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// DO NOT USE #DEFINE INT LONG LONG IN CODE!
// If needed, initialize the multiset as long long normally
template<typename T>
class multi_indexed_set{

    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
	    tree_order_statistics_node_update> miset;
    unordered_map<T, int> freq;

    public:
	void insert(T x){
	    freq[x]++;
	    miset.insert({x, freq[x]});
	}
	void erase(T x){
	    if(!freq[x]) return;
	    miset.erase({x, freq[x]});
	    freq[x]--;
	}
	int order_of_key(T x){ return miset.order_of_key({x, 0}); }
	int count(T x) { return freq[x]; }
	int size(){ return miset.size(); }

};

multi_indexed_set<int> X;


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    
    int y, n;
    cin >> y >> n;
    vector<int> slots (y + 1);
    for (int i = 1; i <= y; i++){
        cin >> slots[i];
    }
    vector<stack<ii>> begin (y + 1);
    vector<stack<ii>> end (y + 1);
    for (int i = 1; i <= n; i++){
        int last, position, f;
        cin >> last >> position >> f;
        begin[last].push({i, position});
        end[last + f].push ({i, position});
    }

    vector<int> ans( n + 1);
    vector<int> quali (n + 1);
    for (int i = 1; i <= y; i++){
        X.insert(slots[i]);
        
        while (begin[i].size() > 0){
            auto [player, position] = begin[i].top();
            begin[i].pop();
            if (slots[i] >= position){
                quali[player] = true;
            }
            if (not quali[player]) ans[player] -=  X.size() -  X.order_of_key(position);
        }
        while (end[i].size() > 0){
            auto [player, position] = end[i].top();
            end[i].pop();
            if (not quali[player]) ans[player] +=  X.size() -  X.order_of_key(position);
        }
        
    }
    for (int i = 1; i <= n ; i ++){
        cout << ans[i] << endl;
    }


    return 0;
    
}