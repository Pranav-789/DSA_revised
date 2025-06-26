#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;

    if(n %2 == 0){
        // k can from 1 to n, but need indices 0 to n/2-1 for k <= n/2
        if(k <= n/2){
            cout << 2*(k-1) +1 << endl;
        }
        else{
            cout << 2*(k-n/2) << endl;
        }
    }
    else{
        if(k <= n/2+1){
            cout << 2 * (k - 1) + 1 << endl;
        }
        else{
            cout << 2*(k-n/2-1) << endl;
        }
    }
    return 0;
}