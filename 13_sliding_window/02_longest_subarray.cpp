#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int>& arr, int k){
    // generate all subarrays and check
    int n = arr.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum <= k){
                maxLen = max(maxLen, j - i + 1);
            }
            else if(sum > k) break;
        }
    }

    cout << maxLen << endl;
}

int betterApproach(vector<int>& arr, int k){
    //use two pointer appraoch
    int maxLen = 0;
    int left = 0, right = 0;

    int sum = 0;

    while(right < arr.size()){     
        sum += arr[right];
        while(sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum <= k){
            maxLen = max(maxLen, right-left+1);                      
        }
        right++;
    }
    cout << maxLen << endl;
    //TC => O(N)
    return maxLen;
}

int optimalApproach(vector<int>& arr, int k){
    int maxLen = 0;
    int left = 0, right = 0;

    int sum = 0;

    while (right < arr.size())
    {
        sum += arr[right];
        if (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum <= k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    cout << maxLen << endl;
    // TC => O(N)
    return maxLen;
}

int main(){
    // longest subarray with sum <= k
    vector<int> arr = {2, 5, 1, 7, 10};
    int k = 14;
    bruteForce(arr, k);
    betterApproach(arr, k);
    return 0;
}