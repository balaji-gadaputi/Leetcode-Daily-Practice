// Last updated: 06/07/2026, 11:59:17
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> l;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                l.push_back(matrix[i][j]);
            }
        }
        sort(l.begin(),l.end());
        return l[k-1];
    }
};