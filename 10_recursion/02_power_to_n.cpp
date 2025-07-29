#include<bits/stdc++.h>
using namespace std;

int pow(double num, int n){
    if(n == 0) return 1;
    double half = pow(num, n/2);
    if(n%2== 0) return half*half;
    return half*half*num;
}

int main(){
    cout << pow(5, 6) << endl;
    cout << pow(2, -4) << endl;
    return 0;
}