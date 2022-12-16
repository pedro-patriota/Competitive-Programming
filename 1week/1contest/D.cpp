#include <iostream>
#include <string>
#include<cstdio>
#include <unordered_map>
#include <math.h>
#include <iomanip>

using namespace std;
int main(){
    int num_input = 0;
    float f, c;
    float new_f, new_c;
    cin >> num_input;

    for (int i  = 0; i < num_input; i ++){
        cin >> c;
        cin >> f;

        new_f = ((float)(9*c)/5) + 32;
        new_f += f;
        new_c = ( (float) (new_f -32)/9)*5;
        cout << "Case " << i+1 << ":" << fixed << setprecision(2) << new_c << "\n";
        
        
    
    }
}