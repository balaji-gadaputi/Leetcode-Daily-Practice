// Last updated: 20/07/2026, 10:50:39
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
16        TreeNode* cur = root; long long prev=LLONG_MIN;
17        stack<TreeNode*> st;
18        while(cur!=nullptr || !st.empty()){
19            while(cur!=nullptr){
20                st.push(cur); cur = cur->left;
21            }
22            cur = st.top(); st.pop();
23            if(cur->val <= prev) return false;
24            prev = cur->val;
25            cur = cur->right;
26        }
27        return true;
28    }
29};