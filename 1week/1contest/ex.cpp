#include <string>
#include <iostream>

using namespace std;

int main(){
    int input = 0;

    while (true){
        cin >> input;
        if (input != 42){
        cout << input << "\n";
        }else{
            break;
        }
    }
    return 0;
}