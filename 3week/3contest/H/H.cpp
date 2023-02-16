    #include <bits/stdc++.h>
    using namespace std;
    long long num_exp, num_food, type_food, l, r, m, temp;
    map<long long, long long> food_map;
    vector<long long> food_arr;

    bool is_possible(long long days)
    {
        temp = 0;
        if (days == 0)
        {
            return true;
        }
        for (long long i = food_arr.size() - 1; i >= 0; i--)
        { // checar se ta pegando o maior sempre
            type_food = food_arr[i];
            temp += type_food / days;
            if (temp >= num_exp)
            {
                return true;
            }
        }
        return false;
    }

    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);
        cin >> num_exp >> num_food;
        for (int i = 0; i < num_food; i++)
        {
            cin >> type_food;
            food_map[type_food]++;
        }
        for (auto it : food_map)
        {
            food_arr.push_back(it.second);
        }
        sort(food_arr.begin(), food_arr.end());
        l = 0;
        r = num_food;
        while (l < r)
        {
            m = (l + r + 1) / 2;
            if (is_possible(m))
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << l;
        return 0;
    }