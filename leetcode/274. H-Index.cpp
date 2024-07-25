#include <bits/stdc++.h>
using namespace std;

/*

[3,0,6,1,5]
-> 5 papers
0 - 3 cit
1 - 0 cit
2 - 6 cit
3 - 1 cit
4 - 5 cit 

h >= 0

0 1 3 5 6 
    ^
min(citations[i], sz_papers - i)

0 - min(0, 5) = 0
1 - min(1, 4) = 1
3 - min(3, 3) = 3
5 - min(5, 2) = 2
6 - min(6, 1) = 1

[3, 1, 1]
1 1 3
1 - min(1, 3) = 1
1 - min (1, 2) = 1
3 - min(3, 1) = 1

[5, 6, 9]
5 -> 3 papers >= 5 citations -> min(citations[i], sz_papers - i)
5 - min(5, 3) -> 3
6 - min(6, 2) -> 2
9 - min(9, 1) -> 1


*/

int hIndex(vector<int>& citations) {
    int sz = citations.size(), sum = 0;
    vector<int> citations_freq(sz+1, 0);
    for (auto v : citations) {
        citations_freq[min(sz, v)]++;
    }
    for (int h = sz; h > 0; h++) {
        sum += citations_freq[h];
        if (sum >= h) {
            return h;
        }
    }
    return 0;
}
