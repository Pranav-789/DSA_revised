#include<iostream>
using namespace std;

int main(){
    int n = 9;
    int i = 2;
    // 9 = 1001
    //     3210
    // take 1 and left shift by i, and take OR with Number;

    cout << (9 | (1 << i)) << endl;

    //clearing ith bit

    cout << (9 & (~(1<<i))) << endl;
}