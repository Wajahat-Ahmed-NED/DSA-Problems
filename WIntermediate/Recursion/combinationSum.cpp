#include <iostream>
#include <vector>
using namespace std;
// No chance of duplication because every integer in input is distinct
class Solution
{
private:
    vector<vector<int>> ans;

public:
    void recursiveFunction(int ind, int target, vector<int> &arr, vector<int> &temp)
    {
        if (ind >= arr.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (arr[ind] <= target)
        {
            temp.push_back(arr[ind]);

            recursiveFunction(ind, target - arr[ind], arr, temp);

            // recursiveFunction(ind+1,target-arr[ind],arr,temp);

            temp.pop_back();
        }

        recursiveFunction(ind + 1, target, arr, temp);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<int> temp = {};
        recursiveFunction(0, target, candidates, temp);

        // vector<vector<int>> result;
        // for(const auto i:ans){
        //     result.push_back(i);
        // }
        return ans;
    }
};