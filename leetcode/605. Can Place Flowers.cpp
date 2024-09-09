#include <bits/stdc++.h>
using namespace std;

/*
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

1, 0, 0, 0, 0, 1 n = 2
false

1, 0, 0, 0, 0, 0 n = 2
true

1 0 1 0 1 0

0 0 0 n = 2
true 

1 n = 0
true

1 n = 1
false


1 Aprroach
1,0,1,0,1
          ^

1, 0, 1, 0, 0, 1   n =2
                 ^

time: O(n)
space: O(1)

*/

bool canPlaceFlowers(vector<int> flowers, int extra_flowers) {
    int cnt = 0, sz = flowers.size();

    for (int i = 0; i < sz; i++) {
        if (flowers[i] == 0) {
            bool can_place_left = true, can_place_right = true;
            if (i > 0 && flowers[i-1] == 1) {
                can_place_left = false;
            }
            if (i < sz -1 && flowers[i+1] == 1) {
                can_place_right = false;
            }
            if (can_place_left && can_place_right) {
                flowers[i] = 1;
                cnt++;
            }
        }
    }
    return cnt >= extra_flowers;
}

int main () {
    vector<int> flowers = {1,0,0,0,1};
    cout << canPlaceFlowers(flowers, 1) << endl; // 1
    cout << canPlaceFlowers(flowers, 0) << endl; // 1
    cout << canPlaceFlowers(flowers, 2) << endl; // 0

    flowers = {1, 0, 0, 0, 0, 1};
    cout << canPlaceFlowers(flowers, 2) << endl; // 0
    flowers = {1, 0, 0, 0, 0, 0};
    cout << canPlaceFlowers(flowers, 2) << endl; // 1
    flowers = {0, 0, 0, 0, 0, 0};
    cout << canPlaceFlowers(flowers, 3) << endl; // 1
    flowers = {1};
    cout << canPlaceFlowers(flowers, 1) << endl; // 0
    flowers = {1};
    cout << canPlaceFlowers(flowers, 0) << endl; // 1

}