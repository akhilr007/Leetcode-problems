class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mini=nums[0];
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
        }
        
        int minMoves=0;
        for(int i=0; i<nums.size(); i++){
            minMoves += nums[i]-mini;
        }
        
        return minMoves;
    }
};