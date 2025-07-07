#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
    int check(vector<int> &arr, int unitsLim) // return for a particulart limit for a painter, how many painter will be required
    {
        int unitsTaken = 0;
        int painters = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (unitsTaken + arr[i] <= unitsLim)
            {
                unitsTaken += arr[i];
            }
            else
            {
                unitsTaken = arr[i];
                painters++;
            }
        }
        return painters;
    }

public:
    int minTime(vector<int> &arr, int k)
    {
        // code here
        int high = 0;
        int low = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            high += arr[i];
            if (arr[i] > low)
            {
                low = arr[i];
            }
        }
        // range will be from max to sum
        // we are focusing on the minimizing the time
        // the min time will never be less than the maxest wall in the array
        // so we try to atleast give everyone the units nearly similar to max of the array, 
        // in doing so if the number of painters exceed the given workforce
        // we increament the units taken per painter, 
        // and do this until we find out the ideal number of units one should take to minimize the time and not exceed the number of painters
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(arr, mid) <= k)
            { // the number of painter are in control, move to left for lesser units
                high = mid - 1;
            }
            else
            {// if painters required are exceeding k, then increase the workload
                low = mid + 1;
            }
        }

        return low;
        // return minimum time
    }
};