#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {-1, 2, 3, 4, 4, 5, -1};
    int k = 4;

    int left = 0, right = k-1;
    int sum = 0;
    for(int i = left; i <= right; i++){
        sum += arr[i];
    }
    int maxSum = sum;

    while(right < arr.size()-1){
        sum = sum - arr[left];
        left++;
        right++;
        sum = sum + arr[right];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;
    return 0;
}