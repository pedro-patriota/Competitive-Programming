#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    string input;

    while (getline(cin, input))
    {
        int pos = input.find("BUG");
        string aux = "";
        string finder = input;
        int j = 0;
        int size = input.size();
        while (pos != -1){
            char z = input[pos];
            z = input[pos+1];
            z = input[pos+2];
            input.replace(pos, pos+3, "");
            pos = input.find("BUG");
        }
        
        cout << input << endl;
    };
}