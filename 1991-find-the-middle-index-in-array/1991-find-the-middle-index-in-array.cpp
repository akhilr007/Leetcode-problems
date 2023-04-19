class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int rightSum = accumulate(begin(nums), end(nums), 0);
        
        int leftSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            rightSum -= nums[i];
            
            if(leftSum == rightSum)
                return i;
            
            leftSum += nums[i];
        }
        
        return -1;
    }
};