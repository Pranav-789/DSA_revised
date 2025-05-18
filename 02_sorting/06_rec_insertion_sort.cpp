#include<iostream>
using namespace std;

void insertionSort(int arr[], int e, int s = 1){
    if (s > e) return;
    int key = arr[s];
    int j = s-1;
    while(j >= 0 && key < arr[j]){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
    insertionSort(arr, e, s+1);
}

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};

    insertionSort(arr, 9, 1);

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
}
