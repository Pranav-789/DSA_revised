#include <bits/stdc++.h>
using namespace std;

void revVector(vector<int>& source, vector<int>& target, int i){
    // Reverses the vector by filling 'target' using recursion
    if(i >= source.size()) return;
    revVector(source, target, i+1);
    target.push_back(source[i]);
}

void revVectorII(vector<int>&source, int low){
    int high = source.size()-low-1;
    if(low >= high) return;
    else{
        int temp = source[low];
        source[low] = source[high];
        source[high] = temp;
    }
    revVectorII(source, low+1);
}

int main()
{
    vector<int> vec = {1, 2, 4, 5, 6, 7, 9, 10};
    vector<int> res;
    revVector(vec, res, 0);

    cout << "Original: ";
    for (auto i : vec)
        cout << i << " ";
    cout << "\nReversed: ";
    for (auto i : res)
        cout << i << " ";

    return 0;
}