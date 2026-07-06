// Last updated: 06/07/2026, 12:00:54
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res; vector<int> path = {};
        recur(candidates,0,target,res,path);
        return res;
    }
    void recur(vector<int> &candidates,int index, int target, 
               vector<vector<int>> &res, vector<int> &path){
        if(target == 0){
            res.push_back(path); return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            path.push_back(candidates[i]);
            recur(candidates, i+1,target-candidates[i],res,path);
            path.pop_back(); 
        }
    }
};