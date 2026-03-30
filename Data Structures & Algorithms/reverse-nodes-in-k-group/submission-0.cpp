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
    ListNode* reverseLL(ListNode* head){
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

    ListNode* findKthNode(ListNode* head,int k){
        k-=1;
        while(head!=nullptr && k>0){
            k--;
            head=head->next;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=nullptr;
        ListNode* newNode=nullptr;
        while(temp!=nullptr){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                if(prevNode) prevNode->next=temp;
                break;
            }
            newNode=kthNode->next;
            kthNode->next=nullptr;
            reverseLL(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=newNode;
        }
        return head;
    }
};
