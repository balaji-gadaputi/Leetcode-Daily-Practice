// Last updated: 06/07/2026, 12:01:04
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr=head;
        int count=0;
        while(ptr && count<k){
            ptr=ptr->next; count++;
        }
        if(count<k) return head;
        ListNode *prev=nullptr,*cur=head,*succeed=nullptr;
        count=0;
        while(count<k && cur){
            succeed=cur->next;
            cur->next=prev; prev=cur;
            cur=succeed; count++;
        }
        if(succeed) head->next=reverseKGroup(succeed,k);
        return prev;
    }
};