#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int num_input, boat_len, num_car, car_len;
    string pos;
    queue<int> left;
    int counter = 0, boat_pos = 0; // 0 left 1 rigth
    queue<int> right;
    cin >> num_input;
    int temp_sum;

    for (int i = 0; i < num_input; i++)
    {
        cin >> boat_len;
        cin >> num_car;
        boat_len *= 100;


        for (int j = 0; j < num_car; j++)
        {
            cin >> car_len;
            cin >> pos;

            if (pos == "left")
            {
                left.push(car_len);
            }
            else
            {
                right.push(car_len);
            }
        }
        while (!left.empty() || !right.empty())
        {
            temp_sum = 0;
            if (boat_pos == 0)
            { // left
                while (true)
                {
                    car_len = left.front();
                    if (temp_sum + car_len > boat_len || left.empty()){
                        break;
                    }else{
                        temp_sum += car_len;
                        left.pop();
                    }
                }
                boat_pos = 1;
                counter += 1;
            }
            else // right
            {
                while (true)
                {
                    car_len = right.front();
                    if (temp_sum + car_len > boat_len || right.empty()){
                        break;
                    }else{
                        temp_sum += car_len;
                        right.pop();
                    }
                }
                boat_pos = 0;
                counter += 1;
            }
        }
        cout << counter << "\n";
        boat_pos = 0;
        counter = 0;
    }
}