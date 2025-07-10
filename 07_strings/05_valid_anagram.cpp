#include <bits/stdc++.h>
using namespace std;

// easy wuestion, just map the frequency of both and compare
// if no match is found, return false


class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        string test = s;
        map<char, int> freq;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (auto fq : freq)
        {
            if (fq.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};