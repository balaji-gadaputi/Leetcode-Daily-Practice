// Last updated: 06/07/2026, 11:59:57
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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root); return res;
    }
    void postorder(TreeNode* root){
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        res.push_back(root->val);
    }
};