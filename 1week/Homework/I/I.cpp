#include <bits/stdc++.h>


using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string input;
    unordered_map<char, int>priority;
    priority['+'] = 0;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 3;
    priority['^'] = 4;
    int num_exp;
    cin >> num_exp;
    cin.ignore();
    stack <char> aux;
    string res;
    for (int i = 0; i < num_exp;i ++){
        getline(cin, input);
        aux = stack<char>();
        res = "";
        for (auto letter : input){
            if (letter == '('){
                aux.push(letter);
            }
            else if (letter == ')'){
                while (!aux.empty() && aux.top() != '(')
                {
                    res += aux.top();
                    aux.pop();
                }
                aux.pop(); // Removes the '(' from the stack
            }
            else if (priority.count(letter)){
                while (!aux.empty() &&  (priority.count(aux.top()) ? priority[aux.top()] >= priority[letter] : false)){
                    res += aux.top();
                    aux.pop();
                }
                aux.push(letter);
            }else{
                res += letter;
            }
        }
        while (!aux.empty()){
            res += aux.top();
            aux.pop();
        }
        cout << res << "\n";

    }

}