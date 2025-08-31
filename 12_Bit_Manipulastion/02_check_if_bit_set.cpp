#include<iostream>
using namespace std;

int main(){
    // example check if second bit of 13 is set or not?

    // int N = 9;
    int N = 13;
    // 13 = 1 1 0 1
    //      3 2 1 0 <- positions
    // left shift 1 by i places, here 1 << 2 => 0100
    //  1 1 0 1
    //& 0 1 0 0
    //---------
    //  0 1 0 0
    // if answer is > 0, then bit is set, otherwise not set;

    int i = 2;

    if(N & (1 << i)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    //using right shift, this time shift number

    if((N>>i) &  1){
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}