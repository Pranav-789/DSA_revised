#include<iostream>
using namespace std;

int main(){
    int N = 13;
    //toggle ith bit
    int i = 1;
    // left shift 1 by i, and take XOR
    cout << (N ^ (1 << i)) << endl;
}