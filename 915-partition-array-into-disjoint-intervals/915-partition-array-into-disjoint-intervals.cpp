class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int leftMax = nums[0];
        int greater = nums[0];
        int ans = 0;
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i] > greater){
                greater=nums[i];
            }
            else if(nums[i] < leftMax){
                leftMax = greater;
                ans = i;
            }
        }
        
        return ans+1;
    }
};