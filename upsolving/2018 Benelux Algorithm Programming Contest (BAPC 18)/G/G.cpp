#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<char, int> freqMap;
int sz;
string input, ans;
vector<int> prefixA;
vector<int> prefixB;
vector<int> prefixC;
int compare (vector<char>& arr){
    int res = INT_MAX;
    int firstQnt, secQnt, thirdQnt, firstPrefix, secPrefix, thirdPrefix;
    firstQnt = freqMap[arr[0]];
    secQnt = freqMap[arr[1]];
    thirdQnt = freqMap[arr[2]];
    for (int i = 0; i < sz; i++){
        int temp_res = 0;

        firstPrefix = prefixA[i+firstQnt] - prefixA[i];
        if (arr[1] == 'B'){
            secPrefix = prefixB[i+firstQnt+secQnt] - prefixB[i+firstQnt];
            thirdPrefix = prefixC[i+firstQnt+secQnt+thirdQnt] - prefixC[i+firstQnt+secQnt];
        }else{
            secPrefix = prefixC[i+firstQnt+secQnt] - prefixC[i+firstQnt];
            thirdPrefix = prefixB[i+firstQnt+secQnt+thirdQnt] - prefixB[i+firstQnt+secQnt];

        }
        temp_res += firstQnt - firstPrefix;
        temp_res += secQnt - secPrefix;
        temp_res += thirdQnt - thirdPrefix;

        res = min(temp_res, res);
    }
    return res;

}   

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> sz;
    cin >> input;
    ans = string(2*sz, '_');
    for (int  i = 0; i < sz; i++)
    {   
        char letter = input[i];
        ans[i] = letter;
        ans[i + sz] = letter;
        freqMap[letter]++;
    }
  
    prefixA = prefixB = prefixC = vector<int>(2*sz + 1);
    prefixA[0] = prefixB[0] = prefixC[0] = 0; 
    for (int i = 0; i < 2*sz; i++){
        
        auto letter = ans[i];
        prefixA[i+1] = prefixA[i] + (letter == 'A' ? 1 : 0);
        prefixB[i+1] = prefixB[i] + (letter == 'B' ? 1 : 0);
        prefixC[i+1] = prefixC[i] + (letter == 'C' ? 1 : 0);        

    }

    // abc
    int res = INT_MAX;
    vector<char> next = {'A', 'B', 'C'};
    res = min(res, compare(next));
    next = {'A', 'C', 'B'};
    res = min(res, compare(next));

    cout << res;
    



    return 0;
}