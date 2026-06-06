class Node {
public:
    int key,val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
};

class LRUCache {
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mpp;
    int limit;

    void insertNode(Node* newNode){
        Node* oldnext=head->next;
        head->next=newNode;
        oldnext->prev=newNode;
        newNode->next=oldnext;
        newNode->prev=head;
    }

    void delNode(Node* oldNode){
        Node* oldnext=oldNode->next;
        Node* oldprev=oldNode->prev;
        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* ansNode=mpp[key];
        int ans=ansNode->val;
        mpp.erase(key);
        delNode(ansNode);
        insertNode(ansNode);
        mpp[key]=ansNode;
        return ans;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* oldnode=mpp[key];
            delNode(oldnode);
            mpp.erase(key);
        }
        if(mpp.size()==limit){
            Node* lru=tail->prev;
            mpp.erase(lru->key);
            delNode(tail->prev);
            delete lru;
        }
        Node* newNode=new Node(key,value);
        insertNode(newNode);
        mpp[key]=newNode;
    }
};
