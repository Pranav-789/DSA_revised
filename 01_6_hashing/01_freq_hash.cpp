#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //pre-compute for max element 13
    int hash[13]={0};
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    int q;
    cin >> q;

    while(q--){
        int num;
        cin >> num;
        cout << "Fetched freq for " << num << ": " << hash[num]<<endl;
    }

    return 0;
}