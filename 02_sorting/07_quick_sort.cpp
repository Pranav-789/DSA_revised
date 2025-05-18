#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] < pivot){
            cnt++;
        }
    }
    int piv_idx = s + cnt;
    swap(arr[s], arr[piv_idx]);
    int i = s, j = e;

    while(i < piv_idx && j > piv_idx){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        
        if(i < piv_idx && j > piv_idx){
            swap(arr[i], arr[j]);
        }
    }

    return piv_idx;
}

void quickSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[10] = {12, 21, 13, 31, 14, 41, 15, 51, 16, 61};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}