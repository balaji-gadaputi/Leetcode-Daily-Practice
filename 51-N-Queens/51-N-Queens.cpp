// Last updated: 27/02/2026, 15:21:59
1class Solution {
2public:
3    vector<bool> pos; vector<bool> neg;
4    vector<bool> column; int n;
5    vector<string> board;
6    vector<vector<string>> ans;
7
8    vector<vector<string>> solveNQueens(int n) {
9        this->n = n;
10        pos = vector<bool>(2*n,true);
11        neg = vector<bool>(2*n,true);
12        column = vector<bool>(n,true);
13        board = vector<string>(n,string(n,'.'));
14        //ans = vector<vector<string>>(n,vector<string>(n))
15        solve(0);
16        return ans;
17    }
18    void solve(int row){
19        if(row == n){
20            ans.push_back(board);
21        }
22        for(int col = 0; col<n; col++){
23            if(place(row,col)){
24                solve(row+1);
25                remove(row,col);
26            }
27        }
28    }
29    bool place(int row, int col){
30        if(column[col] && pos[row+col] && neg[row-col+n]){
31            board[row][col] = 'Q'; // placed the queen
32            column[col] = false;
33            pos[row+col] = false;
34            neg[row-col+n] = false; // blocking the spot
35            return true;
36        }
37        return false;
38    }
39    void remove(int row, int col){
40        board[row][col] = '.';
41        column[col] = true;
42        pos[row+col] = true;
43        neg[row-col+n] = true;
44
45    }
46};