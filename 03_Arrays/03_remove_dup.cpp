#include<bits/stdc++.h>
using namespace std;

//Given: array is sorted

int redDups(vector<int>& nums){
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

int main(){

    return 0;
}