#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n){
    if(n <= 1) return n;
    
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main(){
    int n = 8;

    for (int i = 0; i < 8; i++)
    {
        cout << nthFibonacci(i) << endl;
    }
    
}