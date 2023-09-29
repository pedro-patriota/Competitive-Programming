    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define endl '\n'

    int main()
    {
        ios ::sync_with_stdio(0);
        cin.tie(0);

        int X, minNeeded;
        cin >> X;
        minNeeded = 3000/X;
        if (minNeeded*X < 3000){
            minNeeded++;
        }
        cout << min(minNeeded, 15) << endl;

        
            
        return 0;
        
    }