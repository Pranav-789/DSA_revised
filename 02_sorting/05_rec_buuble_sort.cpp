#include<iostream>
using namespace std;

void bubbleSort(int arr[], int s, int e){
    if(s == e) return;
    for(int i = s; i < e; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, s, e-1);
}

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};

    //bubble sort

    bubbleSort(arr, 0, 9);

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
}