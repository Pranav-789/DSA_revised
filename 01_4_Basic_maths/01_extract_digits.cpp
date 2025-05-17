#include<iostream>
using namespace std;

int main(){
    int N = 77089;
    int cnt = 0;
    while(N!=0){
        cout << N%10 << endl;
        N = N / 10;
        cnt++;
    }

    cout << "There are " << cnt << " digits in N." << endl;

}