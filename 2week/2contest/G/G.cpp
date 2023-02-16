#include <bits/stdc++.h>
using namespace std;
long long n, l, r, num_inputs, init, last, real_l, real_r;
string input, query, X, Y, test;
long long aux;
bool is_reversed = false;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    l--;
    r--;
    cin >> input;
    cin >> num_inputs;
    init = -1;
    last = -1;

    for (int i = 0; i < num_inputs; i++)
    {
        cin >> query;
        if (query == "S")
        {
            cin >> X;
            cin >> Y;
            if (X == "L")
            {
                if (Y == "R")
                {
                    if (is_reversed)
                    {
                        l--;
                    }
                    else
                    {
                        l++;
                    }

                    /* if (l - 1 <= last && l - 1 >= init) // talvez seja >=
                    {
                        l--;
                    } */
                }
                if (Y == "L")
                {
                    if (is_reversed)
                    {

                        if (l + 1 <= last && l + 1 >= init) // talvez seja >=
                        {
                            l++;
                        }
                        else
                        {
                            input.insert(l, 1, input[init - 1]);
                            input.erase(r - 1);
                            init--;
                            last--;
                            r--;
                        }
                    }
                    else
                    {
                        l--;
                    }
                }
            }
            else
            {
                if (Y == "L")
                {
                    if (is_reversed)
                    {
                        r++;
                    }
                    else
                    {
                        r--;
                    }
                    /* if (l - 1 <= last && l - 1 >= init) // talvez seja >=
                    {
                        l++;
                    } */
                }
                if (Y == "R")
                {
                    if (is_reversed)
                    {

                        if (r - 1 <= last && r - 1 >= init) // talvez seja >=
                        {
                            r--;
                        }
                        else
                        {
                            input.insert(r, 1, input[last + 1]);
                            init++;
                            last++;
                            l++;
                            input.erase(last+1, 1);

                        }
                    }
                    else
                    {
                        r++;
                    }
                }
            }
        }
        else if (query == "R")
        {
            if (is_reversed){
                is_reversed = false;
            }else{
                is_reversed = true;
            }
            init = min(l, r);
            last = max(l, r);
            aux = l;
            l = r;
            r = aux;
        }
        else
        {
            cin >> X;
            if (X == "L")
            {
                cout << input[l];
                test += input[l];
            }
            else
            {
                cout << input[r];
                test += input[r];
            }
        }
    }
}