#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find breakdown-point index;
        int index = -1;
        for(int i = nums.size()-2; i>= 0; i--){
            if(nums[i+1]>nums[i]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = nums.size()-1; i>index;i--){
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};
// @lc code=end

