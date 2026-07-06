// Last updated: 06/07/2026, 12:00:38
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *t=head,*prev; int cnt=0;
        if(!head) return nullptr;
        for(ListNode *l=head;l;l=l->next,cnt++);
        k=k % cnt;
        for(int m=0;m<k;m++){
            while(t->next){
                prev=t; t=t->next;
            }
            t->next=head;
            prev->next=nullptr;head=t;
        }
        return head;
    }
};