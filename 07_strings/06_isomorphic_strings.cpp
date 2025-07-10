#include <bits/stdc++.h>
using namespace std;

// Two strings are isomorphic if characters in s can be replaced to get t, with a one-to-one mapping (no two characters in s can map to the same character in t and vice versa).


// this is one tricky question,
// my first thought was to map the element in 's' to corressponding element in 't'
// if the character is not matching to prev mapping, then return false
// but the edge case is as follows
// s->aabb
// t->aaaa
// the the letter a in s maps to a, and b also maps to a,
// which is not a one one relationship as required by 
// to handle this we mapped s with t, and t with s
// that way we ensure that there is a consistent one-one mapping

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, char> mpS, mpT;
        int i = 0;
        while (i < s.size())
        {
            char a = s[i], b = t[i];

            if ((mpS.count(a) && mpS[a] != b) || (mpT.count(b) && mpT[b] != a))
            {
                return false;
            }
            i++;
            mpS[a] = b;
            mpT[b] = a;
        }
        return true;
    }
};