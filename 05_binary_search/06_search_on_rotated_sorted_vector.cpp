#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int index = -1;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == target){
        //         index = i;
        //         break;
        //     }
        // }
        // return index;
        //Okay this was a linear search approach
        // but as it given that the array is sorted and we have to search
        // we can think of binary search

        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[low] <= nums[mid]){
                if(nums[mid] >= target && target >= nums[low]){
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }
            }
            else { //if right part is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    //element exists:
                    low = mid + 1;
                }
                else {
                    //element does not exist:
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};