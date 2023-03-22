#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll unsigned counter, p1_size, p2_size;
ll first_val, last_val;
string str_p1, str_p2, p1, p2;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> str_p2 >> str_p1;
    unsigned ll comb_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
                             1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000,
                             1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000};
    p1_size = str_p1.size();
    if (p1_size > 1)
    {
        counter += 9;
        first_val = stoi(string(1, str_p1[0]));

        for (ll i = 2; i < p1_size; i++)
        {

            counter += 9 * comb_10[i - 2];
        }
        first_val = stoi(string(1, str_p1[0]));
        last_val = stoi(string(1, str_p1[p1_size - 1]));
        if (last_val >= first_val)
        {
            if (p1_size < 3)
            {
                counter += first_val;
            }
            else
            {
                counter += (first_val - 1) * comb_10[p1_size - 2];
                unsigned ll aux_temp = 0;
                for (ll i = 1; i < p1_size - 1; i++)
                {
                    auto int_val = stoi(string(1, str_p1[i]));
                    aux_temp += int_val * comb_10[(p1_size - 2) - i];
                }
                counter += first_val * (max((unsigned ll)1, aux_temp + 1));
            }
        }
        else
        {
            counter += (first_val - 1) * comb_10[p1_size - 2];
        }
    }

    else
    {
        counter += stoi(str_p1);
    }

    p2_size += str_p2.size();
    first_val = stoi(string(1, str_p2[0]));
    last_val = stoi(string(1, str_p2[p2_size - 1]));
    if (p2_size > 1)
    {
        if (last_val == first_val)
        {
            counter++;
        }
        counter -= 9;

        for (ll i = 2; i < p2_size; i++)
        {

            counter -= 9 * comb_10[i - 2];
        }
        if (last_val >= first_val)
        {
            if (p2_size < 3)
            {
                counter -= first_val;
            }
            else
            {
                counter -= (first_val - 1) * comb_10[p2_size - 2];
                unsigned ll aux_temp = 0;
                for (ll i = 1; i < p2_size - 1; i++)
                {
                    auto int_val = stoi(string(1, str_p2[i]));
                    aux_temp -= int_val * comb_10[(p2_size - 2) - i];
                }
                counter -= first_val * (max((unsigned ll)1, aux_temp + 1));
            }
        }
        else
        {
            counter -= (first_val - 1) * comb_10[p2_size - 2];
        }
    }
    else
    {
        counter -= stoi(str_p2) - 1;
    }

    cout << counter;
}