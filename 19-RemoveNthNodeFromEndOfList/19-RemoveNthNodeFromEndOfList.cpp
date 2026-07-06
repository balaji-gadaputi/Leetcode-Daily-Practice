// Last updated: 06/07/2026, 12:01:08
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* h1 = &dummy;
        ListNode* h2 = &dummy;
        for(int i=0; i<=n; i++){
            h2=h2->next;
        }
        while(h2){
            h1 = h1->next; h2 = h2->next;
        }
        ListNode *del = h1->next;
        h1->next = h1->next->next;
        delete del;
        return dummy.next;
    }
};