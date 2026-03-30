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

    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l1=head;
        ListNode* node=slow->next;
        slow->next=nullptr;
        ListNode* l2=reverseList(node);
        ListNode* l1next;
        ListNode* l2next;
        while(l1!=nullptr && l2!=nullptr){
            l1next=l1->next;
            l2next=l2->next;
            l1->next=l2;
            l2->next=l1next;
            l1=l1next;
            l2=l2next;
        }
    }
};
