#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int sum = 0, mx = 0;
    for (auto el : gain) {
        sum += el;
        mx = max(mx, sum);
    }   
    return mx;
}

int main () {

}