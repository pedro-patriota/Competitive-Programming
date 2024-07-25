#include <bits/stdc++.h>
using namespace std;

/*
g = [1, 2, 3, 4, 5]
c = [3, 4, 5, 1, 2]

d = [-2, -2, -2, 3, 3]

d = [3, -2, -2, 3, -2]

g = [4, 3, 4]
c = [3, 4, 3]

pg = [2, 5, 9]
pc = [3, 7, 10]

*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sz = gas.size(), sum_gas, sum_cost, sum, cur_begin;
    sum_cost = sum_gas = sum = cur_begin = 0;

    for (int i = 0; i < sz; i++) {
        sum_gas += gas[i];
        sum_cost += cost[i];
    }

    if (sum_cost > sum_gas) {
        return -1;
    }
    for (int i = 0; i < sz - 1; i++) {
        sum += gas[i] - cost[i];
        if (sum < 0) {
            sum = 0;
            cur_begin = i + 1;
        }
    }
    return cur_begin;
}

int main () {

}