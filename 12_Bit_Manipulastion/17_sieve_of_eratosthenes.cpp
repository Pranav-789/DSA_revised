#include<bits/stdc++.h>
using namespace std;

void primeSeive(int N){
    vector<int> prime(N+1, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i <= N; i++){
        if(prime[i] == 1){
            for(int j = i*i; j <= N; j+= i){
                prime[j] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(prime[i] == 1){
            cout << i << " ";
        }
    }
}

int main(){
    primeSeive(36);
}