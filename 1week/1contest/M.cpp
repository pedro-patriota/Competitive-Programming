#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main()
{
    int candies_packet = 0;
    string is_error;
    map<int, int, greater<int>> table;
    while (true)
    {
        cin >> candies_packet;
        if (candies_packet == -1)
        {
            break;
        }
        for (int i = 0; i < candies_packet; i++)
        {
            table[candies_packet] = i;
        }
        map<int, int, greater<int>> :: iterator it;
        int difference = 0;
        while (true){
            
        }
    }
}