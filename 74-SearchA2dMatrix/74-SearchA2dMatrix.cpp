// Last updated: 06/07/2026, 12:00:30
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(target>matrix[i][matrix[i].size()-1]){
                continue;
            } else{
                for(int j=0;j<matrix[i].size();j++){
                    if(target == matrix[i][j]) return true;
                }
                return false;
            }
        }
        return false;
    }
};