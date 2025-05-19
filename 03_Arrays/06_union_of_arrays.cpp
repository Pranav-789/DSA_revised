#include<bits/stdc++.h>
using namespace std;

void unionArr(vector<int>& ans, vector<int>& Arr1, vector<int>& Arr2){
    //Brute Force
    // set<int> st;

    // for (int i = 0; i < Arr1.size(); i++)
    // {
    //     st.insert(Arr1[i]);
    // }

    // for (int i = 0; i < Arr2.size(); i++)
    // {
    //     st.insert(Arr2[i]);
    // }
    
    //Optimal
    int i = 0, j = 0;
    while(i < Arr1.size() && j < Arr2.size()){
        if(Arr1[i] <= Arr2[j]){
            if(ans.empty() || ans.back() != Arr1[i]){
                ans.push_back(Arr1[i]);
            }
            i++;
        }
        else{
            if(ans.empty() || ans.back() != Arr2[j]){
                ans.push_back(Arr2[j]);
            }
            j++;
        }
    }

    while(i < Arr1.size()){
        if(ans.back() != Arr1[i]){
            ans.push_back(Arr1[i++]);
        }else i++;
    }

    while(j < Arr2.size()){
        if(ans.back() != Arr2[j]){
            ans.push_back(Arr2[j++]);
        }else j++;
    }
}

int main() {
    vector<int> Arr1 = {1, 2, 2, 3, 4};
    vector<int> Arr2 = {2, 3, 5, 6};
    vector<int> ans;

    unionArr(ans, Arr1, Arr2);

    cout << "Union of the two arrays: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
