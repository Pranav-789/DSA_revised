#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2, 2, 1, 2, 1, 1, 4, 3, 4, 4};
    // sort the array => 1, 1, 1, 2, 2, 2, 3, 4, 4, 4 
    //these will bring all the duplicates in clusters

    sort(nums.begin(), nums.end());
    int ans = INT_MIN;
    bool done = false;
    for(int i = 1; i < nums.size(); i+=3){
        if(nums[i] != nums[i-1]){
            ans = nums[i-1];
            done = true;
        }
    }
    if(!done){
        ans = nums[nums.size()-1];
    }

    // TC NlogN + N/3

    cout << ans << endl;
}