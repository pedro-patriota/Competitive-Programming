#include <bits/stdc++.h>
using namespace std;
long long num_seg, seg;
vector<long long> seg_arr;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_seg;
    for (long long i = 0; i < num_seg; i++)
    {
        cin >> seg;
        seg_arr.push_back(seg);
    }
    sort(seg_arr.begin(), seg_arr.end());

    for (long long i = num_seg - 1; i >= 2; i--)
    {
        if (seg_arr[i - 1] + seg_arr[i - 2] > seg_arr[i])
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}