// Last updated: 06/07/2026, 11:59:32
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
    bool isPalindrome(ListNode* head) {
        int count=0;
        for(ListNode *ptr=head;ptr;count++,ptr=ptr->next);
        if(count==0) return false; if(count==1) return true;
        int factor=count/2;
        ListNode *start=head,*mid=head;
        for(int cnt=0; cnt<factor ;cnt++){
            mid=mid->next;
        }

        ListNode *cur=mid,*prev=nullptr,*next=nullptr;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;
        }
        mid=prev;

        while(start && mid){
            if(start->val != mid->val) return false;
            start=start->next; mid=mid->next;
        }
        return true;
    }
};