class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // 1. find repeated number;
        vector<int> res(2);
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            
            if(nums[idx]>0) nums[idx] = -nums[idx];
            else{
                // we got our repeated number;
                res[0] = idx+1;
            }
        }
        
        // 2. find missing number
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0) nums[i] = -nums[i];
            else{
                res[1] = i+1;
            }
        }
        return res;
    }
};