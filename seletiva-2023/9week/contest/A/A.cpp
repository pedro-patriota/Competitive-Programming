#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int test_cases, n, n1, n2;
    cin >> test_cases;
    for (ll i = 0; i < test_cases; i ++){
        set<int> arr1;
        set<int> arr2;
        bool is_pos = true;
        cin >> n;
        for (ll j = 0; j < n; j++){
            cin >> n1 >> n2;
            if (n1 == n2){
                is_pos = false;
            }
            if (is_pos) {

            if (not arr1.count(n1) && not arr1.count(n2)){
                arr1.insert(n1);
                arr1.insert(n2);
            }
            else{
                if (not arr2.count(n1) && not arr2.count(n2)){
                    arr2.insert(n1);
                    arr2.insert(n2);
                }
                else{
                    is_pos = false;
                }
            }
            }
        
        }
        if (is_pos){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;

        }
    }
    
    
}