class Solution {
public:
    priority_queue<int>heap;
    queue<pair<int,int>>que; //remaining_time,available_count
    unordered_map<char,int>mpp;
    int time=0;
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        for(int i=0;i<m;i++){
            mpp[tasks[i]]++;
        }
        for(auto& it:mpp){
            heap.push(it.second);
        }
        while(!heap.empty() || !que.empty()){
            time++;
            if(!heap.empty()){
                int freq=heap.top();
                heap.pop();
                freq--;
                if(freq>0){
                    que.push({freq,time+n});
                }
            }
            //cooldown
            if(!que.empty() && que.front().second==time){
                heap.push(que.front().first);
                que.pop();
            }
        }
        return time;
    }
};
