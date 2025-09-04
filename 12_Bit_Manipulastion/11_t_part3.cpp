#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {4, 4, 4, 2, 5, 5, 5};

    // utilize concept of bucket
    int ones = 0, twos = 0;

    for(int i = 0; i < nums.size(); i++){
        ones = (ones ^nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }

    // 4 = 1 0 0
    // i = 0, nums[i] = 4
    // ones = (0 0 0 ^ 1 0 0) & (1 1 1) // not of 0 0 0 -> 1 1 1
    // ones = 1 0 0
    // twos = (0 0 0 ^ 1 0 0) & (0 1 1) // not of 1 0 0 -> 0 1 1
    // twos = 1 0 0 & 0 1 1
    // twos = 0 0 0

    // so we and with ~ not of one from toggling the number from two, if the same number is present in it and vice versa

    // for i = 1, as the number is, ones = 4 and ~twos (... 1 1 1) 4^4 &(~twos)=> 0
    // twos => 0 0 0 ^ 1 0 0 & (... 111) => 1 0 0 as on above one became zero ~one will not affect

    // for i = 2 num = 4, ones = 0, twos = 4
    // one = 0, as 4 is in twos, there
    // as twos already have 4 4^4 will be 0, therefore twos = 0
    // this way 4 is cleared out

    // only single element remain at the end
    
    cout << ones << endl;
}