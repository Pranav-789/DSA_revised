#include<iostream>
using namespace std;

int main(){
    int N = 13;
    // 16 => 10000 -> only one set bit -> power of 2
    // N = 13, => 1101 -> 3 set bits, not a power of 2

    // example: 32 = 100000
    //          31 = 011111, as we know from previous problem that the rhs of rightmost set bit will be converted to 1 in N-1
    // if we do N & N-1 we will get 0

    if((N & (N-1)) == 0){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}