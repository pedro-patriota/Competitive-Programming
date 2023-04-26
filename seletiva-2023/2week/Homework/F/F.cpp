#include <bits/stdc++.h>
using namespace std;

char elements[4] = {'A', 'C', 'G', 'T'};
string dna;
vector<string>table;
long long num_test, num_letter, mutations, max_mutations;

void makingComb(string temp, int temp_char, int temp_mutation_size){
    if (temp_mutation_size == mutations){
        for (int i  = temp_char; i < dna.size(); i++){
            temp += dna[i];
        }
        table.push_back(temp);
        
    }
    else{
        for (int i = temp_char; i <= dna.size() - (mutations - temp_mutation_size); i++){
            for(auto letter : elements){
                if (letter !=  dna[i]){
                    makingComb(temp + letter, i+1, temp_mutation_size+1);
                }
            }
            temp += dna[i];
        }
    
    
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> num_test;
    for (int i = 0; i < num_test; i++){
        cin >> num_letter >> max_mutations;
        cin >> dna; 
        for (int j = 0; j <= max_mutations;j++){
            mutations = j;
            makingComb("", 0,0 );
            
        }
        cout << table.size() << "\n";
        sort(table.begin(), table.end());
        for (auto val : table){
            cout << val << "\n";
        }
        table.clear();
        

    }

    
}