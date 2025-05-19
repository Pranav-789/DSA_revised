#include<bits/stdc++.h>
using namespace std;

int lnSearch(int key, vector<int> nums){
    int n = nums.size();//as in while decrement befor use
    while(n--){
        if(nums[n] == key) return n;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int index = lnSearch(key, nums);

    if (index != -1)
        cout << "Key found at index (from end): " << index << endl;
    else
        cout << "Key not found." << endl;

    return 0;
}
