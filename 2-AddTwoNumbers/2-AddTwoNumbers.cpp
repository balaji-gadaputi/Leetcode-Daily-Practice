// Last updated: 06/07/2026, 12:01:26
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1=l1,*h2=l2,*h3=nullptr,*tail=nullptr;
        int carry=0;
        while(l1 || l2 || carry){
            int v1= (l1!=nullptr) ? l1->val : 0;
            int v2= (l2!=nullptr) ? l2->val : 0;
            int v3= v1 + v2 + carry;
            carry = v3/10;
            v3 = v3 % 10;
            ListNode *nd=new ListNode(v3);
            if(h3==nullptr) h3=tail=nd;
            else {
                tail->next=nd;
                tail=nd;
            }
            if(l1) l1=l1->next;if(l2) l2=l2->next;
        }
        return h3;
    }
};