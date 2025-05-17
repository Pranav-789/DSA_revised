#include<iostream>
using namespace std;

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};

    //bubble sort

    for(int i = 0; i < 10 - 1; i++){
        for(int j = 0; j < 10 - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
}