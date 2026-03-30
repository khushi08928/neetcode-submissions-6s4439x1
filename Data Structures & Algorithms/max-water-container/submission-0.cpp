class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int left=0;
        int right=n-1;
        int amount;
        int maxarea=0;
        while(left<right){
            amount = (right-left) * min(heights[left] , heights[right]);
            maxarea=max(amount, maxarea);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxarea;
    }
};
