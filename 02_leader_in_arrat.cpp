#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i= arr.size()-1; i>=0; i--){
            if(arr[i] >= maxi){
                maxi= arr[i];
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};