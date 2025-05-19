#include<bits/stdc++.h>
using namespace std;

int sec_larg(vector<int> arr){
    int l = arr[0];
    int sl = INT32_MIN;

    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > l){
            sl = l;
            l = arr[i];
        }else if (arr[i] < l && arr[i] > sl) {
            sl = arr[i];
        }
    }
    return sl==INT32_MIN? -1 : sl;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sec_larg(arr);
    
    if (result == -1) {
        cout << "Second largest element doesn't exist (not enough unique elements)." << endl;
    } else {
        cout << "Second largest element is: " << result << endl;
    }
    return 0;
}