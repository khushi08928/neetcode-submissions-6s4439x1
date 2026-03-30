class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>result(2);
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum==target){
                result[0]=i+1;
                result[1]=j+1;
                return result;
            }else if(sum>target){
                j--;
            }else{
                i++;
            }
        }
    }
};
