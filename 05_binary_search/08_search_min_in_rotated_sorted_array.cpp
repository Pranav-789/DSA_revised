#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int min = 5000;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < min)
            {
                min = nums[mid];
            }
            if (nums[mid] >= nums[low])
            {
                // this half is sorted
                if (nums[low] < min)
                    min = nums[low];
                low = mid + 1;
            }
            else if (nums[mid] <= nums[high])
            {
                if (nums[mid] < min)
                    min = nums[mid];
                high = mid - 1;
            }
            else
            {
                low++;
                high--;
            }
        }
        return min;
    }
};

// The min index is the number of times the array has been rotated