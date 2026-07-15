// Last updated: 15/07/2026, 15:59:52
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* left;
7    Node* right;
8    Node* next;
9
10    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
11
12    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
13
14    Node(int _val, Node* _left, Node* _right, Node* _next)
15        : val(_val), left(_left), right(_right), next(_next) {}
16};
17*/
18
19class Solution {
20public:
21    Node* connect(Node* root) {
22        if(root == NULL) return root;
23        queue<Node*> q; q.push(root);
24        while(!q.empty()){
25            int n=q.size();
26            for(int i=0; i<n; i++){
27                if(i==n-1){ 
28                    q.front()->next = NULL;
29                    if(q.front()->left) q.push(q.front()->left);
30                    if(q.front()->right) q.push(q.front()->right);
31                    q.pop(); break;
32                }
33                if(q.front()->left) q.push(q.front()->left);
34                if(q.front()->right) q.push(q.front()->right);
35                Node* temp = q.front();
36                q.pop(); temp->next = q.front();
37            }
38        }
39        return root;
40    }
41};