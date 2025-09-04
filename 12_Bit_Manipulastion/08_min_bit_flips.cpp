#include<iostream>
using namespace std;

int main(){
    int start = 10; // 1 0 1 0
    int goal = 7; // 0 1 1 1
    // Task: convert start into end
    //  1 0 1 0 -> 0 1 1 1, requires fliping three bits 
    // hint: use XOR operator

    int ans_ini = 10 ^ 7;
    int cnt = 0;

    //  1 0 1 0
    //^ 0 1 1 1
    //  1 1 0 1

    // 10 = 1 0 1 0 (8 + 0 + 2 + 0)
    //  7 = 0 1 1 1 (0 + 4 + 2 + 1)
//needsflips^ ^    ^
// we use XOR operator to mark differing bits, as in new ans only differing bits will be marked set, and rest will be 0 or unset
// hence counting set bit in ans will give the number of bits requiring toggle
    for(int i = 0; i < 32; i++){
        if(ans_ini & (1 << i)) cnt++;
    }

    cout << cnt << endl;
}