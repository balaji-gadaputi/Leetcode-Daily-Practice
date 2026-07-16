// Last updated: 16/07/2026, 14:36:04
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
14    int kthSmallest(TreeNode* root, int k) {
15        if(root == nullptr) return true; int count = 0;
16        stack<TreeNode*> st; long long prev = LLONG_MIN;
17        while( !st.empty() || root != nullptr){
18            while(root != nullptr){ st.push(root); root = root->left; }
19            root = st.top(); st.pop(); count++; 
20            if(count == k) return root->val;
21            root = root->right;
22        }
23        return -1;
24    }
25};