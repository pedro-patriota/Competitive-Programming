#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<pair<int, int>> getDivisors(int num){
    vector<pair<int, int>> divisors;
    for (int i = 1; i*i <= num; i++){
        if (num%i == 0){
            divisors.push_back(pair<int, int>(i, num/i));
        }
    }
    return divisors;
}   
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    vector<char> alfa = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    ll l, w, n, total_A;
    cin >> l >> w >> n; 
    
    total_A = l*w;
    if (total_A%n != 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    auto pairs_div = getDivisors(total_A/n);
    bool is_pos = false;
    ll basis_x, basis_y;
    for (auto val : pairs_div){
        if (l%val.first == 0 && w%val.second == 0){
            is_pos = true;
            basis_x = val.first;
            basis_y = val.second;
            break;
        }else if (l%val.second == 0 && w%val.first == 0){
            is_pos = true;
            basis_x = val.second;
            basis_y = val.first;
            break;
        }
    }
    if (not is_pos){
        cout << "IMPOSSIBLE";
        return 0;
    }
    int letter = 0;

    for (int i = 0; i < l; i++){
        int past_letter = letter;
        for (int j = 0; j < w; j++){
            cout << alfa[letter];
            if ((j+1)%basis_y == 0){
                letter++;
            }
        }
        cout << endl;
        if ((i+1)%basis_x == 0){
            //letter++;
        }else{
            letter = past_letter;
        }

    }

    return 0;
    
}