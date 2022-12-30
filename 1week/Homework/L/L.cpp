#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int tests_cases, blue_army_len, green_army_len, num_battlefields, strength, battles, blue_strength, green_strength;
    multiset<int, greater<int>>blue_army;
    multiset<int, greater<int>>green_army;

    vector<int>rest_blue;
    vector<int>rest_green;
    cin >> tests_cases;
    for (int i  = 0; i < tests_cases ; i++){
        int total_blue = 0, total_green = 0;
        cin >> num_battlefields;
        cin >> green_army_len;
        cin >> blue_army_len;
        for(int j = 0; j < green_army_len; j++){
            cin >> strength;
            total_green += strength;
            green_army.insert(strength);

        }
        for(int j = 0; j < blue_army_len; j++){
            cin >> strength;
            total_blue += strength;
            blue_army.insert(strength);
        }
        if (total_blue == total_green){
           
            cout <<"green and blue died\n\n";
        }
        while (green_army.size() != 0 && blue_army.size() != 0)
        {
            battles = min(green_army.size(), blue_army.size());
            battles = min (battles, num_battlefields);
            rest_blue = vector<int>();
            rest_green = vector<int>();

            for (int k = 0; k < battles; k++){
                blue_strength = *blue_army.begin();
                green_strength = *green_army.begin();
                blue_army.erase(blue_army.begin());
                green_army.erase(green_army.begin());

                if (blue_strength > green_strength){
                    rest_blue.push_back(blue_strength - green_strength);
                }else if (green_strength > blue_strength){

                    rest_green.push_back(green_strength-blue_strength);
                }


            }
            for (auto val : rest_blue){
                blue_army.insert(val);
            }
            for (auto val : rest_green){
                green_army.insert(val);
            }
        }
        
        
        if (green_army.size() > 0){
            cout << "green wins\n";
            for (auto val : green_army){
                cout << val << "\n";
            }
        }
        else if (blue_army.size() > 0){
            cout << "blue wins\n";
            for (auto val : blue_army){
                cout << val << "\n";
            }
        }
        cout << "\n";
        blue_army = multiset<int, greater<int>>();
        green_army = multiset<int, greater<int>>();
        

    }
}