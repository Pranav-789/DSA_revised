#include <bits/stdc++.h>
using namespace std;

// in this, we take first string as base comparison, as we have to find the common prefix in all string
// we compare the other string charcter by character
// where the comparison fails, we break the comparison loop, ans move to next string

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < strs[i].size() && j < ans.size())
            {
                if (strs[i][j] == ans[j])
                {
                    j++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (j == 0)
                ans = "";
            else
                ans = ans.substr(0, j);
        }
        return ans;
    }
};