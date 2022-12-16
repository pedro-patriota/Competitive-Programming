#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    int num_inputs = 0;
    string num1, num2, reverse_sum, reverse_num1, reverse_num2, sum;
    int num1_int, num2_int;
    cin >> num_inputs;
    for (int i  = 0; i < num_inputs; i++){
        cin >> num1;
        cin >> num2;
        num1_int = 0;
        num2_int = 0;
        reverse_num1 = "";
        reverse_num2 = "";
        reverse_sum = "";
        sum = "";

        for (int i = 0; i < num1.size(); i++){
            reverse_num1.insert(0, num1[i] + "");
        }
        for (int i = 0; i < num2.size(); i++){
            reverse_num2.insert(0, num1[i] + "");
        }
        num1_int = stoi(reverse_num1);
        num2_int = stoi(reverse_num2);

        sum = to_string(num1_int + num2_int);
        for (int i = 0; i < sum.size(); i++){
            reverse_sum.insert(0, sum[i] + "");
        }
        cout << reverse_sum << "\n";

    }   
}