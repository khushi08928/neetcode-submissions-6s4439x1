class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>heap; //min heap
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
            if(heap.size()>k){
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size()>k){
            heap.pop();
        }
        return heap.top();
    }
};
