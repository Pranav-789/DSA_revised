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

    for(int i = 0; i < 32; i++){
        if(ans_ini & (1 << i)) cnt++;
    }

    cout << cnt << endl;
}