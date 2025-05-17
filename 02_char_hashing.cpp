#include<iostream>
using namespace std;

int main(){
    string s = "abcdabejc";

    int hash[26] = {0};

    for(int i = 0; i < s.size(); i++){
        int x = s[i]-'a';
        hash[x]++;
    }

    int q;
    cin >> q;

    while(q--){
        char ch;
        cout << "freq of char: ";
        cin >> ch;
        cout << hash[ch-'a'] << endl;
    }
    return 0;
}