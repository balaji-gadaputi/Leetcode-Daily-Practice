// Last updated: 06/07/2026, 11:59:00
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
    ListNode* middleNode(ListNode* head) {
        ListNode *head2=head;ListNode* head3=head;
        while( (head3 != nullptr) && (head3->next!=nullptr) ){
            head2=head2->next;
            head3=head3->next->next;
        }
        return head2;
    }
};