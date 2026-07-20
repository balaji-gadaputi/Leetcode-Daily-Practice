// Last updated: 20/07/2026, 10:26:41
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
14    TreeNode* findMin(TreeNode* root){
15        while(root->left!=nullptr){
16            root = root->left;
17        }
18        return root;
19    }
20    TreeNode* deleteNode(TreeNode* root, int key) {
21        if(root == nullptr) return root;
22        if(root->val > key) root->left = deleteNode(root->left,key);
23        else if(root->val < key) root->right = deleteNode(root->right,key);
24        else{
25            if(root->left == nullptr){
26                TreeNode* temp = root->right;
27                delete root; return temp;
28            }
29            if(root->right == nullptr){
30                TreeNode* temp = root->left;
31                delete root; return temp;
32            }
33            TreeNode* successor_val = findMin(root->right);
34            root->val = successor_val->val;
35            root->right = deleteNode(root->right, successor_val->val);
36        }
37        return root;
38    }
39};