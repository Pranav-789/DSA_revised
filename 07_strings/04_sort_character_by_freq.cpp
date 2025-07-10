#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static bool compareByValue(pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second; // to get descending order of value
    }

public:
    string frequencySort(string s)
    {
        map<char, int> freq;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        } // we use a freq map to store frequency of the characters
        vector<pair<char, int>> vec(freq.begin(), freq.end()); // sort the frequency map;
        sort(vec.begin(), vec.end(), compareByValue);
        string ans = "";
        for (auto &p : vec) // put the characters in the answer, according to their frequency
        {
            ans += string(p.second, p.first);
        }
        return ans;
    }
};