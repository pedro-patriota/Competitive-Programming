#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int multi_test, num_word;
    string word;
    unordered_map<string, int> freq_map;
    vector<vector<string>>table(3);
    vector<int>counter(3, 0);
    cin >> multi_test;

    for (int i  = 0; i < multi_test; i++){
        cin >> num_word;
        freq_map = unordered_map<string, int>();

        for (int j = 0; j < 3; j++){
            for (int k = 0; k < num_word; i++){
                cin >> word;
                table[j].push_back(word);
                freq_map[word]++;
            }
        }
        for (int j = 0; j < 3; j++){
            for (auto str : table[j]){
                if (freq_map[str]  == 1){
                    counter[j] += 3;
                }else if (freq_map[str] == 2){
                    counter[j] += 1;
                }
            }
            cout << counter[j] << " ";
        }
        cout << "\n";
        table = vector<vector<string>>(3);

        counter = vector<int>(3, 0);

    }

}