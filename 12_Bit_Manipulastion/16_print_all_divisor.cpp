#include<bits/stdc++.h>
using namespace std;

int main(){
    int N = 36;
    // divisors -> 1, 2, 3, 4, 6, 9, 12, 18, 36
    // if is divisor then, N/i can be a possible divisor

    // in previous example we iterated till root N

    vector<int> vec;

    for(int i = 1; i*i <= N; i++){
        if(N%i ==0){
            vec.push_back(i);

            if(N/i != i){
                vec.push_back(N/i);
            }
        }
    }

    // TC => O(root(N))

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}