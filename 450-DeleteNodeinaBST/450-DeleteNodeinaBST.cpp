// Last updated: 16/07/2026, 13:08:52
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right)
10 *         : val(x), left(left), right(right) {}
11 * };
12 */
13class Solution {
14public:
15    // Finds the leftmost (minimum) node in a subtree
16    TreeNode* findMin(TreeNode* root) {
17        while (root->left != nullptr) {
18            root = root->left;
19        }
20        return root;
21    }
22
23    TreeNode* deleteNode(TreeNode* root, int key) {
24        if (root == nullptr)
25            return nullptr;
26
27        // Search for the node
28        if (key < root->val) {
29            root->left = deleteNode(root->left, key);
30        }
31        else if (key > root->val) {
32            root->right = deleteNode(root->right, key);
33        }
34        else {
35            // Node found
36
37            // Case 1: No left child
38            if (root->left == nullptr) {
39                TreeNode* temp = root->right;
40                delete root;
41                return temp;
42            }
43
44            // Case 2: No right child
45            if (root->right == nullptr) {
46                TreeNode* temp = root->left;
47                delete root;
48                return temp;
49            }
50
51            // Case 3: Two children
52            TreeNode* successor = findMin(root->right);
53
54            // Copy successor's value
55            root->val = successor->val;
56
57            // Delete the successor
58            root->right = deleteNode(root->right, successor->val);
59        }
60
61        return root;
62    }
63};