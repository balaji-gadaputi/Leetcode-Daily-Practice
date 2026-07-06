// Last updated: 06/07/2026, 12:01:06
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1=list1,*head2=list2,*head3=nullptr,*prev=nullptr,*res=nullptr;
        while(head1 && head2){
            if(head1->val < head2->val){
                ListNode *x=new ListNode(head1->val);head3=x;
                if(prev!=nullptr)prev->next=head3;
                if(prev==nullptr)res=head3;
                prev=head3; head1=head1->next;
            }
            else{
                ListNode *x=new ListNode(head2->val);head3=x; 
                if(prev!=nullptr)prev->next=head3;
                if(prev==nullptr)res=head3;
                prev=head3; head2=head2->next;
            }
        }
        while(head1){
            ListNode *x=new ListNode(head1->val);head3=x;
            if(prev==nullptr)res=head3;
            if(prev!=nullptr)prev->next=head3;
            prev=head3; head1=head1->next;
        }
        while(head2){
            ListNode *x=new ListNode(head2->val);head3=x;
            if(prev==nullptr)res=head3; 
            if(prev!=nullptr)prev->next=head3;
            prev=head3; head2=head2->next;
        }
        return res;
    }
};