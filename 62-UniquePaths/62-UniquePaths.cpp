// Last updated: 06/07/2026, 12:00:37
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> temp(m,vector<int>(n,-1));
        return count(0,0,m,n,temp);
    }
    int count(int i,int j,int m,int n,vector<vector<int>> &temp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        else if(i>=m || j>=n){
            return 0;
        }
        if(temp[i][j] != -1){
            return temp[i][j];
        }
        return temp[i][j]=count(i+1,j,m,n,temp) + count(i,j+1,m,n,temp);
    }
};