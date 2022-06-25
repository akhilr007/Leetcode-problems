class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool changed=false;
        
        for(int i=0; i<nums.size()-1; i++){
            
            if(nums[i] <= nums[i+1]) continue;
            
            if(changed) return false;
            
            // we need to decrese the left element priority
            /*
                i  i+1
            [3, 4, 2]
            */
            if(i == 0 or nums[i+1] >= nums[i-1]){
                nums[i] = nums[i+1];
            }
            /*
            [4, 2]
            */
            else{
                nums[i+1] = nums[i];
            }
            changed = true;
        }
        
        return true;
    }
};