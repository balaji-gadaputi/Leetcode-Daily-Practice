// Last updated: 07/07/2026, 13:30:15
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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            int n=q.size(); vector<int> temp;
            for(int i=0; i<n; i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                temp.push_back(q.front()->val); q.pop();
            }
            res.push_back(temp);
        }
        return res[res.size()-1][0];
    }
};