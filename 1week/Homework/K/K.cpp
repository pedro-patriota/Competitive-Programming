#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int num_input, temp, sum, num1, num2, temp_sum;
    multiset<int, greater<>> min_heap;

    while (true)
    {
        cin >> num_input;
        if (!num_input)
        {
            break;
        }
        temp_sum = 0;
        min_heap = multiset<int, greater<>>();
        for (int i = 0; i < num_input; i++)
        {
            cin >> temp;
            min_heap.insert(temp);
        }
        num1 = *min_heap.begin();
        min_heap.erase(min_heap.begin());
        
        while (!min_heap.empty())
        {
            num2 = *min_heap.begin();
            temp_sum += num1 + num2;
            num1 = temp_sum;
            min_heap.erase(min_heap.begin());
            
        }
        cout << temp_sum << "\n";
    }
}