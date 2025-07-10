#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        // works given that parenthesis is valid
        int open = 0;
        int maxi = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                open++;
                if (open > maxi)
                {
                    maxi = open;
                }
            }
            else if (s[i] == ')')
            {
                open--;
            }
        }
        return maxi;
    }
};