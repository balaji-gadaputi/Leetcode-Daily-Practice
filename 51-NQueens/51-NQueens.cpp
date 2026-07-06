// Last updated: 06/07/2026, 12:00:45
class Solution {
public:
    vector<bool> pos; vector<bool> neg;
    vector<bool> column; int n;
    vector<string> board;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        pos = vector<bool>(2*n,true);
        neg = vector<bool>(2*n,true);
        column = vector<bool>(n,true);
        board = vector<string>(n,string(n,'.'));
        //ans = vector<vector<string>>(n,vector<string>(n))
        solve(0);
        return ans;
    }
    void solve(int row){
        if(row == n){
            ans.push_back(board);
        }
        for(int col = 0; col<n; col++){
            if(place(row,col)){
                solve(row+1);
                remove(row,col);
            }
        }
    }
    bool place(int row, int col){
        if(column[col] && pos[row+col] && neg[row-col+n]){
            board[row][col] = 'Q'; // placed the queen
            column[col] = false;
            pos[row+col] = false;
            neg[row-col+n] = false; // blocking the spot
            return true;
        }
        return false;
    }
    void remove(int row, int col){
        board[row][col] = '.';
        column[col] = true;
        pos[row+col] = true;
        neg[row-col+n] = true;

    }
};