#include <iostream>
#include <string>

using namespace std;

int main(){

    string  newnum1 = "", newnum2 = "", num1, num2;   
    
    cin >> num1;
    cin >> num2;

    for (int i = 2; i >= 0; i++){
        newnum1 += num1[i];
    }
    for (int i = 2; i >= 0; i++){
        newnum2 += num2[i];
    }
    if (stoi(newnum1) > stoi(newnum2)){
        cout << newnum1;
    }else{
        cout << newnum2;
    }

    return 0;
}