#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> d;

    for (int a = 1; a <= 100; a++){
        if (a == d) continue;

        for (int b = a + 1; b <= 100; b++){
            if (b == d) continue;

            vector<int> arrComb;
            if ((b- a) == d) continue;
            if ((b*a) == d) continue;
            if ((b % a == 0 && b/a == d)) continue;
            if ((b+a) == d) continue;

            arrComb.push_back(a);
            arrComb.push_back(b);
            arrComb.push_back((b - a));
            arrComb.push_back((b+a));
            arrComb.push_back((b*a));

            if (b%a == 0) arrComb.push_back((b/a));


            sort(arrComb.begin(), arrComb.end());

            for (int c = b + 1; c <= 100; c++){
                if (c == d) continue;


                for (int i = 0; i < arrComb.size(); i++){
                    // soma
                    int soma = c + arrComb[i];
                    int diff = abs(c - arrComb[i]);
                    int multi = c * arrComb[i];
                    int div = max(arrComb[i], c) % min(arrComb[i], c) == 0 ? max(arrComb[i], c)/min(arrComb[i], c) : -1;
                    vector<int> auxComb;
                    auxComb.push_back(c);
                    auxComb.push_back(soma);
                    auxComb.push_back(diff);
                    auxComb.push_back(multi);
                    if (div != - 1) auxComb.push_back(div);
                    
                    if (div != d && soma != d && multi != d && diff != d){
                        for (auto comb : auxComb){
                            if (d > comb){
                                auto it = lower_bound(arrComb.begin(), arrComb.end(), d - comb) - arrComb.begin();
                                if (it == arrComb.size()) continue;
                                if (comb != c && 


                            }
                        }
                    }
                }



            }
            



        }



    }
    
        
    return 0;
    
}