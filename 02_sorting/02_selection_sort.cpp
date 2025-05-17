#include<iostream>
using namespace std;

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};

    //selection sort

    for(int i = 0; i < 9; i++){
        int min_idx = i;
        for(int j = i+1; j < 10; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
}