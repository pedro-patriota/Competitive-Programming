#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string input;
    string num1, num2;
    int int_num1, int_num2;
    int sum = 0;
    cin >> num1;
    cin >> num2;
    
  
    for (int i = stoi(num1); i <= stoi(num2); i ++){
        sum += i*i;
    }
    cout << sum;

    return 0;
}
