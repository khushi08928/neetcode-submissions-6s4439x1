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
        if(list1==nullptr && list2!=nullptr) return list2;
        if(list1==nullptr && list2==nullptr) return list1;
        if(list1!=nullptr && list2==nullptr) return list1;
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* current=dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                current->next=l1;
                current=current->next;
                l1=l1->next;
            }else{
                current->next=l2;
                current=current->next;
                l2=l2->next;
            }
        }
        if(l1!=nullptr){
            current->next=l1;
        }else{
            current->next=l2;
        }
        return dummy->next;
    }
};
