// floor = largest in array <= x
// ceil = smallest in array >= x

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 80, 90 , 110};
    int target = 25;

    int low = 0, high = arr.size()-1;
    int floor_index = -1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] <= target){
            floor_index = mid;
            low = mid+1; // move to right, it will always be bigger than current
        }
        else{
            high = mid-1; //if it is higher, move to left
        }
    }

    int ceil_index = arr.size();
    int low2 = 0, high2 = arr.size() - 1;

    while (low2 <= high2)
    {
        int mid = (low2 + high2) / 2;
        if (arr[mid] >= target)
        {
            ceil_index = mid;
            high2 = mid - 1; // move to right, it will always be bigger than current
        }
        else
        {
            low2 = mid + 1; // if it is higher, move to left
        }
    }

    cout << "Floor index: " << floor_index << endl;
    cout << "Ceil index: " << ceil_index << endl;
}