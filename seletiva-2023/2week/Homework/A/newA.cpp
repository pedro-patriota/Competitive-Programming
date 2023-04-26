#include <bits/stdc++.h>
using namespace std;
long long test_cases, hard, r, l, m, easy, medium;
int last_type;
long long max_1, no_1, max_no_repetition;
bool is_possible(long long m, long long easy, long long medium)
{
    if (m > medium){ 
        return false;
    }
    max_no_repetition = (m + 1)/2;
    return min(max_no_repetition, easy - m) + min(max_no_repetition, medium - m) + min(max_no_repetition, hard) >= m;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> easy >> medium >> hard;
        r = easy;
        l = hard > 0 ? 1 : 0;
        while (l < r)
        {
            m = (l + r + 1) / 2;
            if (is_possible(m, easy, medium))
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}