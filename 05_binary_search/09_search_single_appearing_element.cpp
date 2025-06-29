#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // so we can get the solution by linear search in O(n) time
        // but as stated we have to find the solution in O(logn) time
        // let's say we apply binary search
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int rightLen = high - mid;
            int leftLen = mid - low;
            if (mid != low && nums[mid] == nums[mid - 1])
            {
                // possibility toward left side
                if (leftLen % 2 == 0)
                {
                    high = mid - 2;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (mid != high && nums[mid] == nums[mid + 1])
            {
                if (rightLen % 2 == 0)
                {
                    low = mid + 2;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[low];
    }
};


// this problem was a tough job
//here's are the problems i encountered while solving this
//out of bound index accessing while comparing mid to mid +1 and mid -1
// how i overcame this? -> put up bound that mid should not be low or high
// second issue i faced going on to wrong side
// take an example [1,1, 2, 2, 3]
// for first iteration index 2 is at mid i check according to condition and move to right 
// my low become index 3 and high to 4
// mid index = 3, as mid can't low or high, the solution at first returned nums[3] which was 2, an incorrect solution
// to fix this i saw that if i found the middle matching pair i should move my low or high pointer beyond the mid and it matching index
// hence i imporoved the code and put 
// high = mid -2 at line 23
// and low = mid +2 at line 34