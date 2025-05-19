#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of steps to rotate: ";
    cin >> k;

    Solution sol;
    sol.rotate(nums, k);

    cout << "Array after rotating by " << k << " steps: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
