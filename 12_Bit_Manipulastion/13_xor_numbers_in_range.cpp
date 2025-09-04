#include<bits/stdc++.h>
using namespace std;

int findxor(int n){
    if(n%4 == 1) return 1;
    if(n%4 == 1) return n+1;
    if(n%4 == 1) return 0;
    else return n;
    return 0;
}

int main(){
    int left = 4;
    int right = 7;

    // req: xor of numbers 4 to 7

    cout << (findxor(left-1)^findxor(right)) << endl;
}