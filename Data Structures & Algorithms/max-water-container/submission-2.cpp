class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater=0;
        int n=heights.size();
        int i=0,j=n-1;
        while(i<j){
            int width=j-i;
            int height=min(heights[i],heights[j]);
            int currwater=width*height;
            maxwater=max(maxwater,currwater);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxwater;
    }
};
