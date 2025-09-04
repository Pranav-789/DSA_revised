#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> oneUnique = {4, 1, 2, 1, 2};
    // we now x^x = 0
    //if there is only one unique number, and all other appear twice, then last remaining will always be the unique number
    int x = 0;
    for(int i = 0; i < oneUnique.size(); i++){
        x = x^ oneUnique[i];
    }
    cout << x << endl;
    // time complexity => O(n)
    return 0;
}