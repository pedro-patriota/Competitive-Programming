#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() + 3000 < t) {
            q.pop();
        }
        return q.size();
    }
};

int main () {

}