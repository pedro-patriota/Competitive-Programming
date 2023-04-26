#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main(){
    int num_input, farmers, farm_size, animals, friendliness, sum;
    float total_aux;
    cin >> num_input;
    for (int i  = 0; i < num_input; i ++){
        cin >> farmers;
        total_aux = 0;
        for (int j  =0 ; j < farmers; j ++){
            cin >> farm_size;
            cin >> animals;
            cin >> friendliness;

            float aux = (float) farm_size/animals;
            aux = aux * friendliness * animals;
            total_aux += aux;
        }
        cout << total_aux << "\n";
    }
}