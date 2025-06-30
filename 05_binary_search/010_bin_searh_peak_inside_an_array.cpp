#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // the brute solution is of complexity O(n) linear search

        // optimal solution
        // check for leftmost extreme
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // check if mid is the peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                // mid lies on increasing curve, therefore maxima lie on rhs
                // therefore move to right
                low = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                // mid lies on decreasing curve, therefore maxima lie on lhs
                // therefore move to left
                high = mid - 1;
            }
            else
            {
                // if you are on minima either side can contain a solution
                // i choose to move on right
                low = mid + 1;
            }
        }
        return -1;
    }
};