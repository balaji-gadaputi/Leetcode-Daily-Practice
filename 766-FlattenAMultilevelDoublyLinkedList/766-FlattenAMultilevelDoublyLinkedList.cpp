// Last updated: 06/07/2026, 11:59:03
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *h=head;
        stack<Node*>st;
        while(h!=nullptr){
            if(h->child != nullptr){
                if(h->next) st.push(h->next);
                h->next=h->child;
                h->next->prev=h;
                h->child=nullptr;
            }
            if (h->next==nullptr && !st.empty()) {
                h->next=st.top();
                st.top()->prev=h;
                st.pop();
            }
            h=h->next;
        }
        return head;
    }
};