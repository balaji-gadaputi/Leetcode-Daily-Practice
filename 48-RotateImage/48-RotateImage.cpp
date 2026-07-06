// Last updated: 06/07/2026, 12:00:48
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix2(matrix.size(),vector<int>(matrix.size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                matrix2[j][matrix.size()-1-i]=matrix[i][j];
            }
        }
        matrix.assign(matrix2.begin(),matrix2.end());
    }
};