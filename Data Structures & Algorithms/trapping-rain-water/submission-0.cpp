class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftmax=height[i];
            int rightmax=height[i];
            for(int j=0;j<i;j++){
                leftmax=max(leftmax,height[j]);
            }
            for(int j=i+1;j<n;j++){
                rightmax=max(rightmax,height[j]);
            }
            ans+=min(leftmax,rightmax)-height[i];
        }
        return ans;
    }
};
