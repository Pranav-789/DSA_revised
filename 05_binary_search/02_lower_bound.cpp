//sorted array
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 8, 8, 10, 10, 11};
    int findLowerBoundOf = 8; //the output should be 5
    int low = 0, high = nums.size()-1;
    int ans = nums.size();

    while(low <= high){
        int mid = (low) + (high-low)/2;
        // if(nums[mid] == findLowerBoundOf){
        //     ans = mid;
        //     high = mid-1; //move to left
        // }
        // else if(nums[mid] > findLowerBoundOf){//move to left
        //     ans = mid;
        //     high = mid -1;
        // }
        if (nums[mid] >= findLowerBoundOf)
        {
            ans = mid;
            high = mid-1;
        }
        else{ // move to right
            low = mid +1;
        }
    }

    //shortcut
    auto lb = lower_bound(nums.begin(), nums.end(), 8); // return an itertor, if you want index subtract nums.begin()
    int lb2 = lower_bound(nums.begin(), nums.end(), 8) - nums.begin(); // return an itertor, if you want index subtract nums.begin()

    cout << " " << *lb << " index: " << lb2 << endl;

    cout << "The lower bound of " << findLowerBoundOf << ": " << ans<< endl;
}