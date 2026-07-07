// Last updated: 07/07/2026, 13:30:10
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
    // max width of each row
    // width = right-left+1
    struct NodeInfo{
        TreeNode* nd; long long idx;
    };
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0; int maxWidth=0;
        queue<NodeInfo> q; q.push({root, 0});
        while(!q.empty()){
            int n=q.size();
            long long left = q.front().idx, right = q.back().idx;
            maxWidth = max(maxWidth, (int)(right-left+1));
            for(int i=0; i<n; i++){ // level by level
                NodeInfo cur = q.front(); q.pop();
                long long idx = cur.idx - left;
                if(cur.nd->left) q.push({cur.nd->left,2*idx});
                if(cur.nd->right) q.push({cur.nd->right,2*idx+1});
            }
        }
        return maxWidth;
    }
};