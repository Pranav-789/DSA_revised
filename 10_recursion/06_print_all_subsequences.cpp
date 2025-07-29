#include<bits/stdc++.h>
using namespace std;


//subsequence -> contiguous/non-contiguous, which follows the order
// example: [3, 1, 2]: 
// subsequences, {1}, {2}, {3}, {3, 1}, {1, 2}, {3, 2}, {3, 1, 2}
// but {1, 3}, {2, 3} are not subsequences, as the order of elements are not maintained

// void printAllSubsequences(vector<int> vec, int size, vector<vector<int>>& ans){
//     if(size == 0){
//         ans.push_back(vec);
//         return;
//     }
//     printAllSubsequences(vec, size-1, ans);
//     for (int i = 0; i < vec.size()/size; i++)
//     {
//         vector<int> res;
//         for(int j = 0; j < vec.size(); j++){
//             if(j >= i && j < (i + size)%size){
//                 continue;
//             }
//             res.push_back(vec[j]);
//         }
//         ans.push_back(res);
//     }
// }

void generateSubsequences(int index, vector<int> &vec, vector<int> &current, vector<vector<int>> &ans)
{
    if (index == vec.size())
    {
        if (!current.empty())
            ans.push_back(current);
        return;
    }

    // Include current element
    current.push_back(vec[index]);
    generateSubsequences(index + 1, vec, current, ans);

    // Exclude current element
    current.pop_back();
    generateSubsequences(index + 1, vec, current, ans);
}

void displaySubsequences(const vector<vector<int>> &ans)
{
    for (const auto &subseq : ans)
    {
        cout << "{ ";
        for (int num : subseq)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main(){
    vector<int> vec = {3, 1, 2};
    vector<vector<int>> ans;
    vector<int> current;
    generateSubsequences(0, vec, current, ans);
    displaySubsequences(ans);
}