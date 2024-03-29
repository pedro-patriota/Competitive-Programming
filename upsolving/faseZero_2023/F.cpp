
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

typedef pair<int,int> ii;

class SArray{

public:
	vector<int> idx;
	vector<int> lcp;
	vector<int> rank;
	string word;

	void process(string &text){

		text += '$';
		word = text;
		int n = text.size();
		rank.resize(n);

		vector<ii> lista;
		for(int i=0;i<n;i++){
			lista.push_back({text[i],i});
		}
		sort(lista.begin(),lista.end());
		for(int i=0;i<n;i++){
			idx.push_back(lista[i].second);
		}
		rank[idx[0]] = 0;
		int classe =0;
		for(int i=1;i<n;i++){
			if(text[idx[i]] != text[idx[i-1]]) classe++;
			rank[idx[i]] = classe;
		}

		int k = 1;
		while(k < n){

			vector<int> aux(n);
			vector<int> count(n,0);

			for(int i=0;i<n;i++){
				count[rank[idx[i]]]++;
			}
			for(int i=1;i<n;i++) count[i] += count[i-1];
			for(int i=n-1;i>=0;i--){
				int x = (idx[i]-k+n)%n;
				aux[count[rank[x]] - 1] = x;
				count[rank[x]]--;
			}
			swap(idx,aux);

			vector<int> novo(n);
			
			novo[idx[0]] = 0;
			classe = 0;
			for(int i=1;i<n;i++){
				if(rank[idx[i]] != rank[idx[i-1]] || rank[(idx[i] + k)%n] != rank[(idx[i-1] + k)%n]){
					classe++;
				}
				novo[idx[i]] = classe;
			}
			swap(rank,novo);
			k += k;
		}

		// lcp
		rank.clear();
		rank.resize(n);
		lcp.resize(n-1);

		for(int i=0;i<n;i++){
			rank[idx[i]] = i;
		}
		k = 0;
		for(int i=0;i<n;i++){
			if(rank[i] == n-1){
				k = 0;
				continue;
			}
			int j = idx[rank[i] + 1];
			while(i + k < n && j+k < n && text[i+k] == text[j+k]){
				k++;
			}
			lcp[rank[i]] = k;
			if(k) k--;
		}
	}

	bool find(string &pat){

		int sz = pat.size();
		int dl = 0;
		int dr = idx.size()-1;	

		for(int i=0;i<sz;i++){

			int s = dl;
			int e = dr;
			while(s < e){
				int p = (s+e)/2;

				int x = idx[p] + i;
				if(word[x] >= pat[i]){
					e = p;
				}
				else{
					s = p+1;
				}
			}
			dl = s;
			e = dr;
			while(s < e){
				int p = (s+e)/2;
				
				int x = idx[p] + i;
				if(word[x] > pat[i]){
					e = p;
				}
				else{
					s = p+1;
				}
			}
			if(word[idx[s]+i] > pat[i]) s--;
			dr = s; 
		}

		return dl <= dr;
	}
};

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q, from, to;
    string dna, protein;
    cin >> n >> m;
    cin >> dna >> protein;
    SArray sArr;
    sArr.process(dna);
    cin >> q;
    
    for (auto val : sArr.lcp){
        cout << val << endl;
    }

 /*    for (int i = 0; i < q; i++){
        cin >> from >> to;
        from--;
        to;
    
    } */

        
    return 0;
    
}


