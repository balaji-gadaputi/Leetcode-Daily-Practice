// Last updated: 20/07/2026, 10:56:47
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
15        if(root == nullptr) return 0; int count=0;
16        TreeNode* cur = root; stack<TreeNode*> st;
17        while(cur!=nullptr || !st.empty()){
18            while(cur!=nullptr){
19                st.push(cur); cur = cur->left;
20            }
21            cur = st.top(); st.pop();
22            count++; if(count == k) return cur->val;
23            cur = cur->right;
24        }
25        return 0;
26    }
27};