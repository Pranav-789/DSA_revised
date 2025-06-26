#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> freq;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        bool AliceWin = false;
        for(auto& frequency: freq){
            if(frequency.second % 2==1){
                AliceWin = true;
                break;
            }
        }
        if(AliceWin){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}