#include<iostream>
using namespace std;

int main(){
    int N = 12;
    // 12 = 1 1 0 0

    // example N = 16=> 10000
    // N = 15 => 01111

    // N = 40 => 101000
    // N = 39 => 100111

    // N = 84 => 1010100
    //               ^   rightmost set bit is turned zero in N-1 and all bits on RHS are set
    // N = 83 => 1010011

    // now if you & N and N-1 then rightmost setbit & with 0 will be unset and RHS of it will remain as it is as x&1 = x, lhs being unaffected

    // to remove last set bit do N & N-1
    // example N = 5 => 0101 & 0100 => 0100

    cout << (N^(N-1)) << endl;

    // check if number is power of two, if answer if 0 then the number is power of 2

}