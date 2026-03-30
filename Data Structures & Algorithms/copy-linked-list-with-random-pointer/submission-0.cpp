/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        unordered_map<Node* , Node*>mpp;
        Node* curr=head;

        while(curr!=nullptr){
            mpp[curr]=new Node(curr->val);
            curr=curr->next;
        }

        Node* temp=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr){
                mpp[temp]->next=mpp[temp->next];
            }else{
                mpp[temp]->next=nullptr;
            }

            if(temp->random!=nullptr){
                mpp[temp]->random=mpp[temp->random];
            }else{
                mpp[temp]->random=nullptr;
            }

            temp=temp->next;
        }
        return mpp[head];
    }
};
