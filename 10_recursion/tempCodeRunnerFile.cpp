        return;
    }
    printAllSubsequences(vec, size-1, ans);
    for (int i = 0; i < vec.size()/size; i++)
    {
        int low = i;
        int high = i+size-1;
        vector<int> res;
        for(int j = 0; j < vec.size(); j++){
            if(j >= low && j <= high){
                continue;
            }
            res.push_back(vec[i]);
        }
        ans.push_back(res);
    }
}

void displaySubsequences(const vector<vector<int>> &ans)
{
    for (const auto &subseq : ans)
    {
        cout << "{ ";
        for (int num : subseq)
      