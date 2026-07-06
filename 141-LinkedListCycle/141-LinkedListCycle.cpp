// Last updated: 06/07/2026, 12:00:01
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ||!head->next) return false;
        ListNode *h1=head,*h2=head;
        while(h1 && h2){
            h1=h1->next;
            h2=(h2)?h2->next:nullptr;
            h2=(h2)?h2->next:nullptr;
            if(h1==h2) return true;
        }
        return false;
    }
};