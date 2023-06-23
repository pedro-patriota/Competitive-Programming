#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    ll x, sum = 0, theorical_sum;
    double mean, diff;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    mean = (double)sum / n;
    diff = abs((double)x - mean);

    if (k >= 1)
    {

        for (int i = 0; i < n; i++)
        {
            mean = (double)(sum - arr[i]) / (n - 1);
            if (abs(x - mean) < diff)
            {
                diff = abs((double)x - mean);
            }
        }
    }
    sort(arr.begin(), arr.end());
    if (k >= 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                mean = (double)(sum - arr[i] - arr[j]) / (n - 2);
                if (abs((double)x - mean) < diff)
                {
                    diff = abs((double)x - mean);
                }
            }
        }
    }
    if (k >= 3)
    {
        multiset<ll> best_diff_sum;
        for (int i = 0; i < n; i++)
        {
            best_diff_sum.insert(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            best_diff_sum.erase(best_diff_sum.find(arr[i]));
            for (int j = 0; j < i; j++)
            {

                theorical_sum = (sum - (x * (n - 3))) - arr[i] - arr[j];
                auto it = best_diff_sum.lower_bound(theorical_sum);

                if (it != best_diff_sum.end())
                {
                    mean = (double)(sum - arr[i] - arr[j] - *it) / (n - 3);
                    if (abs((double)x - mean) < diff)
                    {
                        diff = abs((double)x - mean);
                    }
                }
                if (it != best_diff_sum.begin())
                {
                    mean = (double)(sum - arr[i] - arr[j] - *--it) / (n - 3);
                    if (abs((double)x - mean) < diff)
                    {
                        diff = abs((double)x - mean);
                    }
                }
            }
        }
    }
    if (k >= 4)
    {
        multiset<ll> best_diff_sum;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                best_diff_sum.insert(arr[i] + arr[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++){
                best_diff_sum.erase(best_diff_sum.find(arr[i] + arr[j]));
            }
            for (int j = 0; j < i; j++)
            {
                theorical_sum = (sum - (x * (n - 4))) - arr[i] - arr[j];
                auto it = best_diff_sum.lower_bound(theorical_sum);
                if (it != best_diff_sum.end())
                {
                    mean = (double)(sum - arr[i] - arr[j] - *it) / (n - 4);
                    if (abs((double)x - mean) < diff)
                    {
                        diff = abs((double)x - mean);
                    }
                }
                if (it != best_diff_sum.begin())
                {
                    mean = (double)(sum - arr[i] - arr[j] - *--it) / (n - 4);
                    if (abs((double)x - mean) < diff)
                    {
                        diff = abs((double)x - mean);
                    }
                }
            }
        }
    }

    (cout << fixed).precision(9);
    cout << diff << endl;
    return 0;
}