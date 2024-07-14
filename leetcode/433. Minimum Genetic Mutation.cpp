#include <bits/stdc++.h>
using namespace std;

bool isMutation(string& s1, string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
        }
    }
    return cnt == 1;

}

int minMutation(string startGene, string endGene, vector<string>& bank) {
    queue<string> q;
    vector<bool> visited(bank.size(), false);
    int num_mut = 0;
    
    q.push(startGene);
    while (not q.empty()) {
        int sz = q.size();
        while (sz--) {
            string s = q.front();
            q.pop();

            if (s == endGene) {
                return num_mut;
            }

            for (int i = 0; i < bank.size(); i++) {
                if (not visited[i] && isMutation(s, bank[i])) {
                    visited[i] = true;
                    q.push(bank[i]);
                }
            }

        }
        num_mut++;
    }

    return -1;

}


int main()
{
    
}