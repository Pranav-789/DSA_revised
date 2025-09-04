#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {5, 5, 5, 2, 4, 4, 4};
    // every number appears thrice except one
    // they may or may not be in cluster
    // brute => map the freq TC => O(nlogn)

    // using bitwise
    // 5 -> 1 0 1, 2-> 0 1 0, 4 -> 1 0 0

    // 5-> 1 0 1
    // 5-> 1 0 1
    // 5-> 1 0 1
    // 2-> 0 1 0
    // 4-> 1 0 0
    // 4-> 1 0 0
    // 4-> 1 0 0

    //time>6 1 3 -> if occurence is a mutiple of three then the bit in unique is off,
    // and if it is not multiple of 3, then it will be set
    int ans = 0;
    for(int i = 0; i < 32; i++){
        int cnt = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] & (1 << i)){
                cnt++;
            }
        }
        if(cnt%3 == 1){
            ans = ans | (1 << i);
        }
    }

    // TC => O(N*32) => always in  best and worst

    cout << ans << endl;
    return 0;
}