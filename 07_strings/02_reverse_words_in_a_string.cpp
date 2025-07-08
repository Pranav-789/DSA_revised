#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // the logic is quite simple 
    // take the string and iterate it backwords
    // extract the word, reverse it and append to ans with a " " white space
public:
    string reverseWords(string s)
    {
        string ans = "";
        string word = "";
        int j = s.length() - 1;
        while (j >= 0)
        {
            if (j >= 0 && s[j] == ' ')
                j--; // avoid trailing or begining spaces
            while (j >= 0 && s[j] != ' ')
            {
                word += s[j];
                j--;
            }
            if (!word.empty())
            {
                reverse(word.begin(), word.end());
                ans += word + " ";
            }
            word = "";
        }
        if (!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        // to ensure no trainling space is there after reversing
        return ans;
    }
};
