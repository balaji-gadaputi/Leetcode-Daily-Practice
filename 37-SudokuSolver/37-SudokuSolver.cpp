// Last updated: 02/03/2026, 19:18:29
1class Solution {
2public:
3    vector<vector<bool>> row;
4    vector<vector<bool>> col;
5    vector<vector<bool>> box;
6    vector<pair<int,int>> blanks;
7
8    void solveSudoku(vector<vector<char>>& board) {
9
10        row = vector<vector<bool>>(9,vector<bool>(10,true));
11        col = vector<vector<bool>>(9,vector<bool>(10,true));
12        box = vector<vector<bool>>(9,vector<bool>(10,true));
13
14        for(int i=0; i<9; i++){
15            for(int j=0; j<9; j++){
16                if(board[i][j] == '.') blanks.push_back({i,j});
17                else{
18                    row[i][ board[i][j]-'0' ] = false;
19                    col[j][ board[i][j]-'0' ] = false;
20                    int b = (i/3)*3 + (j/3);
21                    box[b][ board[i][j]-'0' ] = false;
22                }
23            }
24        }
25        solve(0,board);
26    }
27
28    bool solve(int index, vector<vector<char>>& board){
29        if(index == blanks.size()) return true;
30        int r = blanks[index].first , c = blanks[index].second;
31        int b = (r/3)*3 + (c/3);
32        for(int d=1; d<=9; d++){
33            if(place(r,c,b,d,board)){
34                if(solve(index+1, board)) return true;
35                remove(r,c,b,d, board);
36            }
37        }
38        return false;
39    }
40    bool place(int r, int c, int b, int d, vector<vector<char>>& board){
41        if(row[r][d] && col[c][d] && box[b][d]){
42            row[r][d] = false; col[c][d] = false;
43            box[b][d] = false; board[r][c] = d+'0';
44            return true;
45        }
46        return false;
47    }
48    void remove(int r, int c,int b, int d, vector<vector<char>>& board){
49        row[r][d] = true; col[c][d] = true;
50        box[b][d] = true; board[r][c] = '.';
51    }
52};