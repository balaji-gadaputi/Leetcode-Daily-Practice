// Last updated: 06/07/2026, 11:59:55
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        while(fast != NULL && fast->next != NULL){
            temp = slow; slow = slow->next;
            fast = fast->next->next;
        } temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return MergeSort(l1,l2);
    }
    ListNode* MergeSort(ListNode* l1, ListNode* l2){
        ListNode* ptr = new ListNode(0);
        ListNode* cur = ptr;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        if(l1 != NULL){
            cur->next = l1; l1 = l1->next;
        }
        if(l2 != NULL){
            cur->next = l2; l2 = l2->next;
        }
        return ptr->next;
    }
};