#include <bits/stdc++.h>
#define ii tuple<int, int, int>
using namespace std;

priority_queue<int> half1;
priority_queue<int, vector<int>, greater<int>> half2;

void addNum(int num) {
    if (half1.empty()) {
        half1.push(num);
    } else {
        if (num < half1.top()) {
            half1.push(num);
        } else {
            half2.push(num);
        }
    }
    if (half1.size() + 1 < half2.size()) {
        auto x = half2.top();
        half2.pop();
        half1.push(x);
    } else if (half2.size() + 1 < half1.size()) {
        auto x = half1.top();
        half1.pop();
        half2.push(x);
    }
}

double findMedian() {
    double ans;
    if (half1.size() == half2.size()) {
        ans = (double)(half1.top() + half2.top()) / 2;
    } else if (half1.size() > half2.size()) {
        ans = (double) half1.top();
    } else {
        ans = (double) half2.top();
    }
    return ans;
}
