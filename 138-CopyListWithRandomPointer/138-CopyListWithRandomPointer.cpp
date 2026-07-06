// Last updated: 06/07/2026, 12:00:03
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *h1=head, *h2=nullptr, *head2=nullptr;
        vector<Node*>vec;int cnt=0;
        for(h1=head;h1;h1=h1->next,cnt++){
            Node *temp=new Node(h1->val);
            temp->next=nullptr;
            vec.push_back(h1->random);
            if(!h2){ head2=temp;h2=temp;}
            else{h2->next=temp; h2=temp;}
        }
        h1=head; h2=head2;
        for(int i=0;i<cnt;i++){
            int count=0;
            if(vec[i]==nullptr){
                h2->random=nullptr;
            }
            else{
                for(Node *k=head; k!=vec[i]; k=k->next){
                    count++;
                }
                Node *k=head2;
                for(int c=0;c<count;c++) k=k->next;
                h2->random=k;
            }
            h2=h2->next; h1=h1->next;
        }
        return head2;
    }
};