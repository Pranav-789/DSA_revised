#include<iostream>
using namespace std;

int main(){
    int a = 56, b = 24;

    while(a > 0, b > 0){
        if(a > b) a -= b;
        else b -= a;
    }

    cout << ((a!=0)? a:b) << endl;
}