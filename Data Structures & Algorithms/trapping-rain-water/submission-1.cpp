class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        vector<int>leftmax(n,0);
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i-1]);
        }
        vector<int>rightmax(n,0);
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        }
        int maxwater=0;
        for(int i=0;i<n;i++){
            int min_val=min(leftmax[i],rightmax[i]);
            maxwater+=max(0,min_val-height[i]);
        }
        return maxwater;
    }
};
