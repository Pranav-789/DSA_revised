#include<iostream>
using namespace std;

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};

    //selection sort

    for(int i = 1; i < 10; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
}