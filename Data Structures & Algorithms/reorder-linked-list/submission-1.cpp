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
private:
    ListNode* reverseLL(ListNode* slow){
        ListNode* curr=slow;
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
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reverseList=reverseLL(slow->next);
        slow->next=nullptr;
        ListNode* p1=head;
        ListNode* p2=reverseList;
        ListNode* p1next;
        ListNode* p2next;
        while(p1!=nullptr && p2!=nullptr){
            p1next=p1->next;
            p2next=p2->next;
            p1->next=p2;
            p2->next=p1next;
            p1=p1next;
            p2=p2next;
        }
    }
};
