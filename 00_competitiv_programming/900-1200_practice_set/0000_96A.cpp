#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int zeroCnt = 0, cncZeroCnt = 0;
    int oneCnt = 0, cncOneCnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            zeroCnt++;
            if(oneCnt > cncOneCnt){
                cncOneCnt = oneCnt;
            }
            oneCnt = 0;
        }
        else{
            oneCnt++;
            if(zeroCnt > cncZeroCnt){
                cncZeroCnt = zeroCnt;
            }
            zeroCnt = 0;
        }
    }
    if(zeroCnt > cncZeroCnt) cncZeroCnt = zeroCnt;
    if(oneCnt > cncOneCnt) cncOneCnt = oneCnt;
    if(cncZeroCnt >= 7 || cncOneCnt >= 7){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}