#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;
int main(){
    int input;
    string s1, s2;
    cin >> input;
    unordered_map<char, int>table;
    unordered_map<char, int>table2;
    unordered_map<char, int>aux;
    int sum =0;

    for (int i = 0; i < input; i ++){
        cin >> s1;
        cin >> s2;
        int s1_size = s1.size();
        int s2_size = s2.size();
        int sum = 0;

        if (s1_size < s2_size){
            for (int i = 0; i < s1_size; i++){
                if (s1[i] == s2[i]){
                    sum += 1;
                }
            }
        }else{
            for (int i = 0; i < s1_size; i++){
                if (s1[i] == s2[i]){
                    sum += 1;
                }
            }

        }
        cout << sum << endl;
    }
}