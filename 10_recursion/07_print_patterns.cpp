#include<bits/stdc++.h>
using namespace std;

void subsequenceSum(int index, vector<int> vec, vector<int> ds, int sum, int req){
    if(index == vec.size()){
        if(sum == req){
            for (int val : ds)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(vec[index]);
    subsequenceSum(index+1, vec, ds, sum + vec[index], req);
    ds.pop_back();
    subsequenceSum(index+1, vec, ds, sum, req);
}

bool printOneSubsequence(int index, vector<int> vec, vector<int> ds, int sum, int req)
{
    if (index == vec.size())
    {
        if (sum == req)
        {
            for (int val : ds)
            {
                cout << val << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(vec[index]);
    if (printOneSubsequence(index + 1, vec, ds, sum + vec[index], req))
    {
        return true;
    }
    ds.pop_back();
    if (printOneSubsequence(index + 1, vec, ds, sum, req))
    {
        return true;
    }
    return false;
}

int main(){
    vector<int> vec = {1, 2, 1};
    vector<int> ds;
    subsequenceSum(0, vec, ds, 0, 2);
    return 0;
}