class Solution {
public:
    int trap(vector<int>& height) {
        int maxwater=0;
        int n=height.size();
        int i=0,j=n-1;
        int leftmax=INT_MIN;
        int rightmax=INT_MIN;
        while(i<j){
            leftmax=max(leftmax,height[i]);
            rightmax=max(rightmax,height[j]);
            if(leftmax<rightmax){
                maxwater+=leftmax-height[i];
                i++;
            }else{
                maxwater+=rightmax-height[j];
                j--;
            }
        }
        return maxwater;
    }
};
