#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<string, char> patternMap;
    vector<bool> wasUsed (26, false);
    string word = "";
    int i = 0;
    s += " ";

    for (auto l : s) {
        if (l != ' ') {
            word += l;
        } else {
            if (i == pattern.size()) {
                return false;
            }

            if (not patternMap.count(word)) {
                if (wasUsed[pattern[i] - 'a']) {
                    return false;
                }
                wasUsed[pattern[i] - 'a'] = true;
                patternMap[word] = pattern[i];
            } else if (patternMap[word] != pattern[i]) {
                return false;
            }

            i++;
            word = "";
        }
    }
    if (i != pattern.size()) {
        return false;
    }

    return true;
}

/*
    abba
        i

    dog cat cat dog

    dog -> a
    cat -> b
    cat -> ? -> map(cat) == i 
                        -> true -> continue, move i
                        -> fasle- > return false

    dog -> ? -> match(dog) == i -> true
 
    if i is at the end of pattern and we are still reading string s, then return false
    if processing of string s is finished but i is not at the end of pattern, then return false
    return true

*/


int main()
{
    
}