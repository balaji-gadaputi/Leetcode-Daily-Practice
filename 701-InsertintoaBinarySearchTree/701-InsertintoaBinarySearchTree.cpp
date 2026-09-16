// Last updated: 16/09/2026, 11:41:04
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* insertIntoBST(TreeNode* root, int val) {
15        TreeNode* cur = root;
16        if(cur == nullptr) return new TreeNode(val);
17        while(root){
18            if(root->val > val){
19                if(root->left != nullptr){
20                    root = root->left;
21                } else{
22                    root->left = new TreeNode(val); return cur;
23                }
24            }
25            if(root->val < val){
26                if(root->right != nullptr){
27                    root = root->right;
28                } else{
29                    root->right = new TreeNode(val); return cur;
30                }
31            }
32        }
33        return root;
34    }
35};