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
        cin >> price;
        int day_min = 0, day_max = 0;

        min_price = price, max_price = price;
        for (int i = ; i < num_days; i++)
        {
            cin >> price;
            if (price < min_price){
                // mark
                min_price = price;
                counter += i - day_min;
                day_min = i;

            }else if (price > max_price){
                max_price = price;
            }
            else if (price < max_price){
                // mark
                max_price = price;
                counter += i - day_min;
            }
            
        }
        cout << counter << "\n";
    }
}