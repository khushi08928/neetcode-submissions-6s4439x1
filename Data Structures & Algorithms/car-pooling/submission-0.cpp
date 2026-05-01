class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int m=0;
        for(auto& trip:trips){
            m=max(m,trip[2]);
        }
        vector<int>arr(m+1,0);
        for(auto& trip:trips){
            arr[trip[1]]+=trip[0];
            arr[trip[2]]-=trip[0];
        }
        int curr=0;
        for(int i=0;i<=m;i++){
            curr+=arr[i];
            if(curr>capacity) return false;
        }
        return true;
    }
};