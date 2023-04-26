#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int num_apt, num_habit, max, mim;
    cin >> num_apt;
    cin >> num_habit;

    vector<int>building (num_apt);

    if (num_apt == num_habit){
        cout << "0 0";
    }else if (num_habit == 0){
        cout << "0 0";
    }else{
        int three_space = num_apt/3;
        int three_possible = min(three_space, num_habit);
        if (three_possible == num_habit){
            max = 2*three_possible;
        }
        else if (num_habit <= three_possible){
            max = num_apt - num_habit;
        }
        else if (num_habit > three_possible){
            int extra_space = num_apt - three_possible*3;
            max = three_possible*2  +  (extra_space - (num_habit - three_possible));
        }

        mim = 1;
        cout << min << " " << max;

    }

}