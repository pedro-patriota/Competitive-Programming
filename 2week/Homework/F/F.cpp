#include <bits/stdc++.h>
using namespace std;

char elements[4] = {'A', 'C', 'G', 'T'};
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    long long num_test, num_letter, mutations;
    string dna;
    cin >> num_test;
    for (int i = 0; i < num_test; i++){
        cin >> num_letter >> mutations;
        vector<string>table;
        cin >> dna;

        for (int mask = (2^mutations-1); mask < (1 << num_letter); mask += mutations){
            
        }

        

    }

    
}