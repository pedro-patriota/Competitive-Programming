#include <bits/stdc++.h>
using namespace std;

/*
never sell for a price that worths less

1. We always want to have a sotck in hands
2. The maximum profit will be the longest increasing sequence 
3. If price decrease from currPrice:
    3.1 Sell last price and set currPrice to new price
4. Else
    4.1 Do nothing 

profit = 0 + (3 - 3) + (7 -1) + (10 - 4) =12
currPrice = 4
3 1 7 4 10
           ^

profit = (100 -1) = 99
currPrice = 100
[1, 3, 5, 10, 100]
                   ^

profit = (7-7) + (5 -1) + (6 - 3) + (4 -4) -> 4 + 3 = 7
currPrice = 7 -> 1
[7,1,5,3,6,4]
           ^

min = 0
buy for the lowest value
sell for the highest value

profit = (5 -1) = 4
[1,2, 3, 4, 5] 

*/

int maxProfit(vector<int>& prices) {
    int curr_price = prices[0], profit = 0;
    prices.push_back(-1);
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < prices[i-1]) {
            profit += prices[i-1] - curr_price;
            curr_price = prices[i];
        } 
    }
    return profit;
}
