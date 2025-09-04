#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2, 4, 2, 14, 3, 7, 7, 3};
    // here there are two distinct numbers
    
    // all elements are appearing twice, and there are two unique numbers

    // XOR will remove the numbers appeaaring twice, but we will be remaining with ans = x^y

    // here also use concept of buckets

    // XOR = 2^2^7^7^3^3^14^4
    // => 6^4 => 1110 ^ 0100 => 1010 i.e. 10, there wil be minimum of one bit which we will be different in 6 and 4

    // take rightmost set bit from obtained 1 0 1 0

    // we do (num&(num-1))^num => you get rightmost bit and everything as 0

    // 1 0 1 0
    //&1 0 0 1
    //--------
    // 1 0 0 0
    //^1 0 1 0
    //--------
    // 0 0 1 0 -> 2

    // seperation

    // traverse through array xor with the rightmost set bit, if ans is zero, the number fall in bucket 2, if not then bucket 1
    // vector

    int xored = 0;
    // Step 1: XOR of all elements → this removes all duplicate pairs
    // After this, xored = unique1 ^ unique2

    for(int i= 0; i < nums.size(); i++){
        xored ^= nums[i];
    }

    int rightMost = (xored ^ (xored-1)) & xored;
    // Step 2: Find the rightmost set bit of xored
    // This bit tells us at which position the two unique numbers differ

    int bucket1 = 0;
    int bucket2 = 0;

    for(int j = 0; j < nums.size(); j++){
        if(nums[j] & rightMost){
            bucket1 = bucket1 ^ nums[j];
            // If the bit is set → number goes into bucket1
            // XOR inside bucket cancels duplicates, leaves one unique
        }
        else{
            bucket2 = bucket2 ^ nums[j];
            // If the bit is not set → number goes into bucket2
            // Same cancellation happens here
        }
    }

    cout << bucket1 << " " << bucket2 << endl;
}