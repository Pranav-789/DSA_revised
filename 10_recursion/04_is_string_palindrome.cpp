#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int low, int high){
    if(low >= high) return true;

    if(s[low] != s[high]) return false;

    return isPalindrome(s, low+1, high-1);
}

int main(){
    string s = "racecar";
    cout << isPalindrome(s, 0, s.length()-1) << endl;
}