#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of to sqrt: ";
    cin >> n;
    int ans = INT16_MIN;

    //Naive approach: 
    // for(int i = 1; i <= n; i++){
    //     if(i*i == n){
    //         ans = i;
    //         break;
    //     }
    //     else if(i*i > n){
    //         ans = i-1;
    //         break;
    //     }
    // }

    //Better approach, using binary search:
    int low = 0, high = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(mid*mid == n){
            ans = mid;
            break;
        }
        else if(mid*mid < n){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }

    cout << "The square root of " << n << ": " << ans << endl;

    return 0;
}