#include<bits/stdc++.h>
using namespace std;

int N = 1e5 +1;
vector<int> spf(N);

int main(){
    for (int i = 0; i < N; i++)
    {
        spf[i] = i;
    }

    int M = 5;
    vector<int> queries = {12, 13, 35, 17, 25};

    for(int i = 2; i*i <= N; i++){
        if(spf[i] == i){
            for(int j = i*i; j <= N; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    for(int i = 0; i < M; i++){
        int T = queries[i];
        cout << T << ": ";
        while(T != 1){
            cout << (spf[T]) << " ";
            T = T/spf[T];
        }
        cout << endl;
    }
    return 0;
}