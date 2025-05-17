#include<iostream>
using namespace std;

int main(){
    int N = 7789;
    int revNum = 0;

    while(N!=0){
        int r = N%10;
        revNum = revNum*10 + r;
        N = N/10;
    }

    cout << revNum << endl;
}