#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    stack<int> gift_pile;
    int num_input, fun;
    string query;
    multiset<int> table;
    vector<int> min_heap;
    make_heap(min_heap.begin(), min_heap.end(), greater<>{});

    int min_fun = INT32_MIN;

    for (int i = 0; i < num_input; i++)
    {
        cin >> query;
        if (query == "PUSH")
        {
            cin >> fun;
            gift_pile.push(fun);

            table.insert(fun);
            min_heap.push_back(fun);
        }
        else if (query == "POP")
        {   

            auto itr = table.find(gift_pile.top());
            gift_pile.pop();
            if (itr != table.end())
            {
                table.erase(itr);
            }
        }
        else
        {
            cout << *table.begin() << endl;
        }
    }
}