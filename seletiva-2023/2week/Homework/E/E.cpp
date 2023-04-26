#include <bits/stdc++.h>
using namespace std;
vector<string> words;
void compiler(string combination, string act_string){
    if (combination.size() != 0){
        for (int i = 0; i < combination.size(); i++){
            char letter = combination[i];
            combination.erase(i, i + 1);

            string temp;
            if (letter =='0'){
                for (int i = 0; i < 10; i++){
                    temp = act_string + to_string(i);

                    compiler(combination, temp);
                }
                return;
            }
            else{
                for (auto wrd : words){
                    temp = act_string + wrd;
                    compiler(combination, temp);
                }
                return;
            }
        }
    }else{
        cout << act_string << "\n";
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int num_words, num_rules;
    string password, rule;
    while (cin >> num_words)
    {
        words = vector<string>(num_words);
        cout << "--\n";
        for (int i = 0; i < num_words; i++)
        {
            cin >> words[i];
        }
        cin >> num_rules;
        for (int i = 0; i < num_rules; i++)
        {
            cin >> rule;
            compiler(rule, "");
            
        }
    }
}