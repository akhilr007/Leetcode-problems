class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int leftMax = nums[0];
        int partitionMax = nums[0];
        int pa = 0;
        
        for(int i=1; i<nums.size(); i++){
            
            if(leftMax <= nums[i]){
                leftMax = nums[i];
            }
            else if(nums[i] < partitionMax){
                pa = i;
                partitionMax = leftMax;
            }
        }
        
        return pa+1;
    }
};