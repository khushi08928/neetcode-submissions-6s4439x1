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
        ListNode* dummyNode=new ListNode(0);
        ListNode* curr=dummyNode;
        int carry=0;
        int totalsum;
        while(l1!=nullptr || l2!=nullptr){
            totalsum=carry;
            if(l1!=nullptr){
                totalsum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                totalsum+=l2->val;
                l2=l2->next;
            }

            carry=totalsum/10;
            int currnum=totalsum%10;
            curr->next=new ListNode(currnum);
            curr=curr->next;
        }
        if(carry>0){
            curr->next=new ListNode(carry);
        }
        return dummyNode->next;
    }
};
