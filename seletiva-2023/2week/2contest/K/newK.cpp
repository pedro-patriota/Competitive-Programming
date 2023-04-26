#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int num_sets, num_days, price, min_price = -1, max_price = -1;
    cin >> num_sets;
    for (int i = 0; i < num_sets; i++)
    {
        int counter = 0;
        multimap<int, int> table;
        vector<int>register_price;
        cin >> num_days;
        int min = INT32_MAX;
        
        for (int i = 0; i < num_days; i++)
        {
            cin >> price;
            register_price.push_back(price);   
            
        }
        for (int i = num_days -1; i >= 0; i--)
        {
            if (register_price[i] < min){
                min = register_price[i];
            }else if (register_price[i] > min){
                counter++;
            }
        }
        cout << counter << "\n";
    }
}