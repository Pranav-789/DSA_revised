#include<iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n != 0){
        // if(n%2 == 1) cnt++;
        if(n&1) cnt++; // condition for checking odd number
        // note odd number will always have its last bit set(1)
        n = n/2;
    }
    return cnt;
}

int otherWay(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}
// example 13 => 1 1 0 1
//         12 => 1 1 0 0 // and them and you will get 1 1 0 0, turning off rightmost set bit
// every time we do N & (N-1) we will set one set bit off
// so number of times it takes to number to reach zero via this method is the number of set bits

int main(){
    cout << countSetBits(16) << endl;
    cout << otherWay(16) << endl;
    return 0;
}