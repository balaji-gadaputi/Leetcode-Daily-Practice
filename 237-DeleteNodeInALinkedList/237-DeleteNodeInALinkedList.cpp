// Last updated: 06/07/2026, 11:59:31
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
    void deleteNode(ListNode* node) {
        ListNode *cur=node, *succeeding=node, *prev=node;
        while(cur->next && succeeding){
            succeeding=cur->next;
            swap(cur->val,succeeding->val);
            prev=cur;
            cur=cur->next;
        }
        prev->next=nullptr;
    }
};