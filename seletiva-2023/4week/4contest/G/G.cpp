#include <bits/stdc++.h>
using namespace std;

long long test_Cases, px, py, testx, testy;
string orders;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test_Cases;
    for (long long test = 0; test < test_Cases; test++){
        cin >> px >> py;
        cin >> orders;
        if (orders.size() < px + py){
            cout << "NO" << "\n";
        }
        testx = testy = 0;
        for (long long i = 0; i < orders.size(); i++){
            if (testy == py && testx == px){
                break;
            }
            if (orders[i] == 'U'){
                if (py > 0 && testy < py){
                    testy++;
                }
            }
            else if (orders[i] == 'D'){
                if (py < 0 && testy > py){
                    testy--;
                }
            }
            else if (orders[i] == 'L'){
                if (px < 0 && testx > px){
                    testx--;
                }
            }
            else if (orders[i] == 'R'){
                if (px > 0 && testx < px){
                    testx++;
                }
            }

        }
        if (testy == py && testx == px){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    
}