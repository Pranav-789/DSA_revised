// LeetCode 977 - Squares of a Sorted Array:
 class Solution
 {
 public:
     vector<int> sortedSquares(vector<int> &nums)
     {
         vector<int> ans(nums.size(), 0);
         int low = 0, high = nums.size() - 1;
         int n = nums.size() - 1;
         while (low <= high)
         {
             if (abs(nums[low]) < abs(nums[high]))
             {
                 ans[n] = nums[high] * nums[high];
                 n--;
                 high--;
             }
             else
             {
                 ans[n] = nums[low] * nums[low];
                 n--;
                 low++;
             }
         }
         return ans;
     }
     // The naive approach takes nlogn time
     //     -first: to square all numbers O(n)
     //     -second: sort the array O(nlogn)
     //for getting the answer in O(n) time, we get the low and high pointer
     // as it is given in question that the array constructed as a non decreasing array
     // we check from both pointer low and high, whose mod or absolute value is higher, and then sqaure the number and put it inside the array
     // then accordingly we move the low or high pointer towards the center
 };

// LeetCode 167 - Two Sum II (Sorted Array):
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0, high = numbers.size() - 1;
        int sum = 0;
        vector<int> ans;
        while (low < high)
        {
            sum = numbers[low] + numbers[high];
            if (sum == target)
            {
                ans.push_back(low + 1);
                ans.push_back(high + 1);
                return ans;
            }
            else if (sum < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        ans = {-1, -1};
        return ans;
    }
    //here we took a tow pointer approach, to get the answer in O(n) time
    //space complexity = O(1)
    //what i did here is took extreme ends, as the array is sorted, left will always be minimum, and right will always be maximum for each iteration
    //so we check the sum of both, if it is equal the, then we return them, but as specified, we have to return 1-based indexing, so i add 1 to bot low and high in the answer
    //if sum is less than target, then an element from low or high is becoming a shortage, to remove this, we move the left pointer one step right, so it gets an increased value
    // if sum is greater than target, that means the high is overpowering, hence we move it one step left, to a lower value
};

// 977B - Two-gram
 #include <bits/stdc++.h>
 using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<string, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        string slice = s.substr(i, 2);
        mp[slice]++;
    }

    int maxfreq = -1;
    string ans = "";
    for (auto i : mp)
    {
        if (i.second > maxfreq)
        {
            maxfreq = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;
    return 0;
    // a simple approach here just map the frequency in ine iteration as we have to check for max freq of two consecutively appearing characters
    // in second loop we find the most occuring substring and return the answer
}

// Q 486A - Calculating Function
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    if (n % 2 == 1)
    {
        ans = -1 * (n % 2 + n / 2);
    }
    else
    {
        ans = 1 * (n % 2 + n / 2);
    }

    cout << ans << endl;
    return 0;
}