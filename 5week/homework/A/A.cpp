#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num_books, money;
vector<ll> val_book;
vector<ll> pages_book;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_books >> money;
    val_book = pages_book = vector<ll>(num_books);
    for (ll i = 0; i < num_books; i++){
        cin >> val_book[i];
    }
    for (ll i = 0; i < num_books; i++){
        cin >> pages_book[i];
    }
    vector<vector<int>> dp(num_books+1, vector<ll>(money+1));
    for (ll item = 1; item <= num_books; item++){
        for (ll act_money = 0; act_money <= money; act_money++){
            ll pegar_item = -1;
            ll nao_pegar_item = dp[item-1][act_money];
            if (act_money >= val_book[item-1]){
                pegar_item = dp[item-1][act_money - val_book[item-1]] + pages_book[item-1];
            }
            dp[item][act_money] = max(pegar_item, nao_pegar_item);
        }
    }
    cout << dp[num_books][money];
    
    
}