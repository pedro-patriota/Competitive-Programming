#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int it = 0;
vector<int> test(vector<int> arr)
{
    int n = arr.size(), i = 0;
    vector<int> op;
    vector<int> pos (n + 1);
    for (int i = 1; i <= n; i++){
        pos[arr[i- 1]] = i;
    }
    for (int i = 1; i <= n; i++){
        if (arr[i-1] != i){    
            op.push_back(i);
            op.push_back(pos[i] - i);
            op.push_back(n - pos[i] + 1);
            
            pos[arr[i-1]] = pos[i];
            swap(arr[i-1], arr[pos[i] -1]);
            pos[i] = i;
        }
    }
    return op;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    auto v1 = test(arr1);
    auto v2 = test(arr2);
    int sz1 = v1.size(), sz2 = v2.size();
    if(sz1%2!=sz2%2&&n%2==0&&m%2==0) std::cout << -1 << "\n";
	else {
		if(sz1%2!=sz2%2) {
			if(n%2) {
				for(int i=1;i<=n;i++) v1.push_back(1);
			}
			else {
				for(int i=1;i<=m;i++) v2.push_back(1);
			}
		}
		int minv = std::min(v1.size(), v2.size());
		int maxv = std::max(v1.size(), v2.size());
		for(int i=v1.size()+1;i<=maxv;i++) {
			if(i&1) v1.push_back(1);
			else v1.push_back(n);
		}
		for(int i=v2.size()+1;i<=maxv;i++) {
			if(i&1) v2.push_back(1);
			else v2.push_back(m);
		}
		std::cout << maxv << "\n";
		
		for(int i=0;i<maxv;i++) {
			std::cout << v1[i] << " " << v2[i] << "\n";
		}
	}

    return 0;
}