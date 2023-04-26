#include <bits/stdc++.h>
using namespace std;
int MAX_SET = 50001;
string s, temp_s;
int counter;
deque<char> dominant_s;
bool is_possible(int set_size)
{
    counter = 0;
    map<char, int> pos_table;

    for (int i = 0; i < set_size; i++)
    {
        pos_table[s[i]] = i;
    }
    for (int i = set_size; i < s.size(); i++)
    {

        if (pos_table.size() == 0)
        {
            return false;
        }

        for (auto it = pos_table.begin(); it != pos_table.end(); it)
        {
            if (it->first == s[i])
            {
                it->second = set_size - 1;
                ++it;
            }
            else if (it->second > 0)
            {
                it->second += -1;
                ++it;
            }
            else if (it->second == 0)
            {
                pos_table.erase(it++);
            }
        }
    }
    if (pos_table.size() == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int l, r, m;
    l = 1;
    r = (s.size()) / 2 + 1;

    while (l < r)
    {
        m = (l + r) / 2;

        if (is_possible(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << l;
}