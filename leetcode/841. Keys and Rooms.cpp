#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int> to_visit_rooms;
    unordered_set<int> keys_collection;

    int sz = rooms.size(), room_index;
    keys_collection.insert(0);
    to_visit_rooms.push(0);

    while (to_visit_rooms.size() > 0) {
        room_index = to_visit_rooms.top();
        to_visit_rooms.pop();
        for (auto key : rooms[room_index]) {
            if (not keys_collection.count(key)) {
                keys_collection.insert(key);
                to_visit_rooms.push(key);
            }
        }
    }
    
    return keys_collection.size() == sz;
}

int main () {

}