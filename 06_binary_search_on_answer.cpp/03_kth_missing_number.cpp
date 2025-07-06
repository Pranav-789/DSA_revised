#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // from constraints i have that maximum of the number can be 2000
        // int missing = 0, prevmissing = -1;
        // int i;
        // for (i = 0; i < arr.size(); i++)
        // {
        //     if (arr[i] != i + 1 && i == 0)
        //     {
        //         prevmissing = missing;
        //         missing += arr[i] - 1;
        //     }
        //     else if (arr[i] != i + 1)
        //     {
        //         prevmissing = missing;
        //         missing += arr[i] - arr[i - 1] - 1;
        //     }

        //     if (missing >= k)
        //     {
        //         break;
        //     }
        // }
        // int ans = -1;
        // if (i == arr.size())
        // {
        //     return arr.back() + (k - missing); // kth missing is after the last element
        // }

        // return arr[i] - (missing - k + 1);
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - mid - 1;
            if (missing >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low + k;
    }
};