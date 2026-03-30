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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* traverseNode=head;
        int count=0;
        while(traverseNode!=nullptr){
            count+=1;
            traverseNode=traverseNode->next;
        }
        if(count==n){
            ListNode* resulthead=head->next;
            delete head;
            return resulthead;
        }
        int index=count-n;
        ListNode* curr=head;
        for(int i=1;i<index;i++){
            curr=curr->next;
        }

        ListNode* nthNodetodelete = curr->next;
        curr->next=curr->next->next;
        delete nthNodetodelete;
        return head;
    }
};
