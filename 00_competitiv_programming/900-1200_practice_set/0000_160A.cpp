#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int n, int sum){
    sort(coins.begin(), coins.end());
    int newSum = 0;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        newSum += coins[i];
        cnt++;
        if (newSum > floor(sum / 2))
        {
            break;
        }
    }
    return cnt;
}

int main(){
    int n; //number of coins
    cin >> n;

    vector<int> coins(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        sum += coins[i];
    }
    
    cout << minCoins(coins, n, sum) << endl;
    return 0;
}