class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int minLength = INT_MAX;
        
        int i=0;
        int j=0;
        
        int curSum=0;
        while(j<nums.size()){
            
            curSum += nums[j];
            
            while(curSum > target){
                minLength = min(minLength, j-i+1);
                curSum -= nums[i];
                i++;
            }
             
            if(curSum == target){
                minLength = min(minLength, j-i+1);
            }
            
            j++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};