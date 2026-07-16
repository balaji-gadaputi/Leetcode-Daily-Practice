// Last updated: 16/07/2026, 14:32:55
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
14    bool isValidBST(TreeNode* root) {
15        if(root == nullptr) return true;
16        stack<TreeNode*> st; long long prev = LLONG_MIN;
17        while( !st.empty() || root != nullptr){
18            while(root != nullptr){ st.push(root); root = root->left; }
19            root = st.top(); st.pop();
20            if(root->val <= prev) return false;
21            prev = root->val;
22            root = root->right;
23        }
24        return true;
25    }
26};