#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int it = 0;
int test (vector<int> A){
    int half = A.size()/2;
    vector<int> sorted, result (A.size());
    int c = 1;
    for (int i  = 0; i < half; i++){
        if (c > A.size() -1) {cout << c; break;}
        result[c] = A[i];
        c += 2;
    }
    c = 0;
    for (int i  = half; i < A.size(); i++){
        result[c] = A[i];
        c += 2;
    }
    sorted = A;
    sort(sorted.begin(), sorted.end());
    
    if (it != 0){
        if (sorted == A) return it;
    }
    it++;
    return test(result);
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int i = 1;
    vector<int> A;
    while (i < 1000){
        i++;
    }
    cout << test({1, 2, 3, 4, 5, 6});
    
        
    return 0;
    
}