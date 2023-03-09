class Solution {
public:
    bool check(vector<int>& nums) {
        
        int breakCount = 0;
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i-1] > nums[i])
                breakCount++;
        }
        
        if(breakCount == 0)
            return true;
        
        if(breakCount == 1 && nums[0] >= nums[nums.size()-1])
            return true;
        
        return false;
    }
};