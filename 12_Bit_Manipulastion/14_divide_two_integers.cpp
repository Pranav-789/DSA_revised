#include<bits/stdc++.h>
using namespace std;

int naive(int a, int b){
    int sign = (a^b) < 0 ? -1 : 1;
    a = abs(a);
    b = abs(b);

    int cnt = 0;
    while(a >= b){
        a-= b;
        cnt++;
    }
    return cnt*sign;
}

int optimal(int a, int b){
    int sign = (a ^ b) < 0 ? -1 : 1;
    a = abs(a);
    b = abs(b);
    // ex. 22/3
    // closes 3*7 -> 7 can be written as 2^2 + 2^1 + 2^0
    int ans = 0;
    while (a >= b){
        int cnt = 0;
        while(a >= (b << (cnt+1))){
            cnt++;
        }
        ans += (1 << cnt);
        a = a - (b * (1 << cnt));
    }
    return ans*sign;
}

int main(){
    cout << optimal(81, 3) << endl;
}