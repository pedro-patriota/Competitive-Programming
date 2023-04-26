#include <bits/stdc++.h>
using namespace std;
long long test_cases, sx, sy, endX, endY, l, m, r, moves;
string input;
bool found;
void recursv(long long sx, long long sy, long long temp_moves){
    if (found){
        return;
    }
    if (temp_moves > moves){
        return;
    }
    if (sx == endX && sy == endY){
        found = true;
        return;
        
    }
    
        if (sx + 2 < 8){         
            if (sy + 1 < 8){
                recursv(sx+2, sy+1, temp_moves+1);
            }
            if (sy -1 >= 0){
                recursv(sx+2, sy-1, temp_moves+1);
            }
        }
    
    
        if (sx - 2 >= 0){         
            if (sy + 1 < 8){
                recursv(sx-2, sy+1, temp_moves+1);
            }
            if (sy -1 >= 0){
                recursv(sx-2, sy-1, temp_moves+1);
            }
        }
    
    
        if (sy + 2 < 8){
            if (sx + 1 < 8){
                recursv(sx+1, sy+2, temp_moves+1);
            }
            if (sx -1 >= 0){
                recursv(sx-1, sy+2, temp_moves+1);
            }
        }
  
        if (sy -2 >= 0){
            if (sx + 1 < 8){
                recursv(sx+1, sy-2, temp_moves+1);
            }
            if (sx -1 >= 0){
                recursv(sx-1, sy-2, temp_moves+1);
            }
        }
        
    
}
bool is_possible(){
    moves = m;
    found = false;
    recursv(sx, sy, 0);
    return found;
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (long long test = 0; test < test_cases; test++){
        cin >> input;
        sx = input[0];
        sy = input[1];
        cin >> input;
        endX = input[0];
        endY = input[1];
        sx -= 97;
        sy -= 49;
        endY -= 49;
        endX -= 97;

        l = 0;
        r = 128;
        while (l < r){
            m = (l + r)/2;
            if (is_possible()){
                r = m;
            }else{
                l = m + 1;
            }
        }
        cout << l << "\n";
    }
    
    
}