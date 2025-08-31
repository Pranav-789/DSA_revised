#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3};
    // subsets => {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}
    // number of subsets are 2^n or (1 << n), where n = number of elements
    // index 2 1 0
    //       0 0 0 -> 0
    //       0 0 1 -> 1
    //       0 1 0 -> 2
    //       0 1 1 -> 3
    //       1 0 0 -> 4
    //       1 0 1 -> 5
    //       1 1 0 -> 6
    //       1 1 1 -> 7
    // 0 -> not take, and 1-> take
    int num_of_subsets = (1 << nums.size());
    vector<vector<int>> vec;
    for(int i = 0; i < num_of_subsets; i++){
        vector<int> list;
        for(int j = 0; j < nums.size(); j++){
            if(i & (1 << j)){
                list.push_back(nums[j]);
            }
        }
        vec.push_back(list);
    }

    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    // time complexity (2^n) * n
}