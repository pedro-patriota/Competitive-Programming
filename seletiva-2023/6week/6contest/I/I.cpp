#include <bits/stdc++.h>
using namespace std;
#define ll long long
int laptops, price, qual;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> laptops;
    map<int, int>arr;
    for (int i = 0; i < laptops; i++){
        cin >> price >> qual;
        arr[price] = qual;
    }
    auto last = arr.end();
    last--;
    bool is_pos = false;
    for (auto it = arr.begin(); it != last; it++ ){
        auto aux = it;
        aux++;

        if (it->second > aux->second ){
            is_pos = true;
            break;
        }

    }
    if (is_pos){
        cout << "Happy Alex";
    }else{
        cout << "Poor Alex" ;
    }
    
    
}