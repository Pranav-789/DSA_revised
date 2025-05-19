#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> nums){
    bool flag = true;
    for (int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i] > nums[i+1]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (isSorted(nums)) {
        cout << "The array is sorted in non-decreasing order." << endl;
    } else {
        cout << "The array is NOT sorted." << endl;
    }

    return 0;
}