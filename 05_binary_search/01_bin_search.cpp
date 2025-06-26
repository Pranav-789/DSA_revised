#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // Binary Search
        int i = -1;
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2; // for preventing overflow
            // mid = (start+end)/2
            if (nums[mid] == target)
            {
                i = mid;
                break;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return i;
    }
};