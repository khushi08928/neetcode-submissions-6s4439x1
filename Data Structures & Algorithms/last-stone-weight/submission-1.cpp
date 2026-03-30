class Solution {
public:
    priority_queue<int>heap;
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        for(int i=0;i<n;i++){
            heap.push(stones[i]);
        }
        while(heap.size()>1){
            int oneEl=heap.top();
            heap.pop();
            int secEl=heap.top();
            heap.pop();
            if(oneEl==secEl){
                continue;
            }else{
                int diff=oneEl-secEl;
                heap.push(diff);
            }
        }
        if(heap.empty()) return 0;
        return heap.top();
    }
};
