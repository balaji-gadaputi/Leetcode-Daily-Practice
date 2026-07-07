// Last updated: 07/07/2026, 13:30:05
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    struct NodeInfo{
        TreeNode* nd; int row;
    }; struct state{
        TreeNode* nd; int row; int col;
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return res;
        map<int,vector<pair<int,int>>> mp;
        queue<state> q; q.push({root,0,0});
        while( !q.empty() ){
            state curr = q.front(); q.pop();
            mp[curr.col].push_back( {curr.row,curr.nd->val});
            if(curr.nd->left) q.push({curr.nd->left, curr.row+1, curr.col-1}); 
            if(curr.nd->right) q.push({curr.nd->right, curr.row+1, curr.col+1});
        }
        for(auto &it:mp){
            sort(it.second.begin(), it.second.end());
            vector<int> col;
            for(auto i:it.second){
                col.push_back(i.second);
            }
            res.push_back(col);
        }
        return res;
    }
};