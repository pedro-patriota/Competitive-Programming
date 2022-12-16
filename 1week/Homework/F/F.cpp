#include <bits\stdc++.h>
using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    deque<int> ladybug_list;

    int num_queries, size = 0, num;
    string query;
    cin >> num_queries;
    unordered_map<string, int>table;
    int is_reversed = 0;

    for (int i = 0; i < num_queries; i++)
    {
        cin >> query;
        if ((query == "toFront" && is_reversed == 0) || (query == "push_back" && is_reversed == 1) )
        {
            cin >> num;
            ladybug_list.push_front(num);
            size++;
        }
        else if ((query == "push_back" && is_reversed == 0)|| (query == "toFront" && is_reversed ==1))
        {
            cin >> num;
            ladybug_list.push_back(num);
            size++;
        }
        else if (query == "reverse")
        {
            if (is_reversed == 0){
                is_reversed = 1;
            }else{
                is_reversed = 0;
            }
        }
        else if ((query == "front"  && is_reversed == 0) || (query == "back"   && is_reversed == 1))
        {
            if (size == 0)
            {
                cout << "No job for Ada?"
                     << "\n";
            }
            else
            {
                cout << ladybug_list.front() << "\n";
                ladybug_list.pop_front();
                size--;
            }
        }
        else if ((query == "front"  && is_reversed == 1) || (query == "back"   && is_reversed == 0))
        {
            if (size == 0)
            {
                cout << "No job for Ada?"
                     << "\n";
            }
            else
            {
                cout << ladybug_list.back() << "\n";
                ladybug_list.pop_back();
                size--;
            }
        }
    }
}