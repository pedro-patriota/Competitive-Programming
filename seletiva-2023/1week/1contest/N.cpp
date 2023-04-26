#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
int main(){
    string inputstring;
    int vel, time;
    while(getline(cin, inputstring)){
        int empty = inputstring.find(" ");
        vel = stoi(inputstring.substr(0, empty));
        time = stoi(inputstring.substr(empty+ 1, inputstring.size()));

        cout << vel*time*2 << "\n";
    }
}