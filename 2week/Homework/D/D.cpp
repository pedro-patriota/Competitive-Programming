#include <bits/stdc++.h>
using namespace std;
const int space = 2.6e4;
vector<long long> A(space), B(space), C(space), D(space);
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long long num_input, a, b, c, d, num_input2;
    cin >> num_input;
    num_input2 = num_input*num_input;
    vector<long long> AplusB (num_input2);
    vector<long long> CplusD (num_input2);

    for (long i = 0; i < num_input; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    long long counter = 0;
    long long aux = 0;
    for (long i = 0; i < num_input; i++){
        for (long j = 0; j < num_input; j++){
            AplusB[aux] = (A[i] + B[j]);
            CplusD[aux] = (C[i] + D[j]);
        
            aux ++;
        }
    }
    sort(AplusB.begin(), AplusB.end());
    for (auto it : CplusD){
        auto in_between = equal_range(AplusB.begin(), AplusB.end(), -it);
        counter += in_between.second - in_between.first ;
    }
    cout << counter;
    
}