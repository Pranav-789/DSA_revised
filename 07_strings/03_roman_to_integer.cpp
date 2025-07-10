#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int romInt(char ch)
    {
        if (ch == 'I')
            return 1;
        if (ch == 'V')
            return 5;
        if (ch == 'X')
            return 10;
        if (ch == 'L')
            return 50;
        if (ch == 'C')
            return 100;
        if (ch == 'D')
            return 500;
        if (ch == 'M')
            return 1000;
        return -1;
    } // this is a helper function that helps easy conversion from roman to int

public:
    int romanToInt(string s)
    {
        if (s.length() == 0)
            return 0;
        int ans = 0; // we use this at start to store the answer
        for (int i = 0; i < s.length() - 1; i++) // we loop through each character and decide
        {
            if (romInt(s[i]) > romInt(s[i + 1])) // if current is greater than next, then it is to added, as the next we be suffix
            { // suffixes increament the values
                ans += romInt(s[i]);
            }
            else if (romInt(s[i]) < romInt(s[i + 1]))
            {
                // if the current is < next, then it is a prefix, 
                // prefix decrease the value of next
                ans -= romInt(s[i]);
            }
            else
            {
                ans += romInt(s[i]); // if current and next are same then just add then up in answer
            }
        }
        ans += romInt(s[s.length() - 1]); // the last character left in loop will always be a suffix, so we add it in answer
        return ans;
    }
};