#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    int num_cocktails, juice, temp_sum = 0;
    cin >> num_cocktails;
    int total = num_cocktails*100;
    for (int i = 0; i < num_cocktails; i++){
        cin >> juice;
        temp_sum += juice;
    }
    cout << (float) total/temp_sum;
}