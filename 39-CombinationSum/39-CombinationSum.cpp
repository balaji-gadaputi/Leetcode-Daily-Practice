// Last updated: 06/07/2026, 12:00:55
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; vector<int> path = {};
        recur(candidates,0,target,res,path,0);
        return res;
    }
    void recur(vector<int> &candidates,int index, int target, 
               vector<vector<int>> &res, vector<int> &path, int sum){
        if(target == sum){
            res.push_back(path); return;
        }
        if(index == candidates.size() || sum > target) return;
        // recursive calls => Pick / Not Pick
        path.push_back(candidates[index]);
        recur(candidates, index,target,res,path,sum+candidates[index]);
        path.pop_back(); 
        recur(candidates, index+1,target,res,path,sum); //without Recursive call
    }
};