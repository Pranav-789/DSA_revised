#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
 if(n <= 1) return false;

 if(n == 2) return true;

 for(int i = 2; i * i <= n; i++){
    if(n%i == 0){
        return false;
    }
 }
 return true;
}

void vectorFill(vector<int>& vec, int N){
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            if (prime(i))
            {
                vec.push_back(i);
            }
        }
    }

    // Time Complexity: 
    //      outer loop: N-1 iterations
    //      inner check goes for orime check -> TC => O(root(N));
    //      worst case: all iterations invoke prime overall TC O(N root(N))
}

void vetorFillII(vector<int>& vec, int N){
    for(int i = 1; i*i <= N; i++){
        if(N%i == 0){
            if(prime(i)){
                vec.push_back(i);
            }
        }
        if(N/i != i){
            if(prime(N/i)){
                vec.push_back(N/i);
            }
        }
    }

    //here we are checking for i and N/i, and iterations are root(N)
    //TC => worst case is approximated to O(root(N) * 2 * root(N))
}

void vectorFillIII(vector<int>& vec, int N){

    // for (int i = 2; i <= N; i++)
    // {
    //     if (N % i == 0)
    //     {
    //         while (N % i == 0)
    //         {
    //             N = N / i;
    //         }
    //         vec.push_back(i);
    //     }
    //     if (N == 0)
    //         break;
    // }

    // TC => O(max(primeFactors)), 
    // Large prime Number TC => O(N)

    for (int i = 2; i*i <= N; i++)
    {
        if (N % i == 0)
        {
            while (N % i == 0)
            {
                N = N / i;
            }
            vec.push_back(i);
        }
        if (N == 0)
        break;
    }
    if(N!= 1) vec.push_back(N); // this check is because if the number itself is prime number, then it will not com in for loop as it does not have the root,
    //hence we manually check and add 
    // TC => O(root(N)*log(N)) // logN because of division-> approximated
}

int main(){
    int N = 37;
    // factors => 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60
    // prime factors => 2, 3, 5

    vector<int> vec;

    vectorFillIII(vec, N);

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}