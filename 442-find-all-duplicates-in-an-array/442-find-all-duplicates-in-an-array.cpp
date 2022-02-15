class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            
            int idx = abs(nums[i])-1;
            int val = nums[idx];
            
            if(val<0){
                // it means we have already marked it before thus add the idx+1 to our ans
                res.push_back(idx+1);
            }
            else{
                // we are coming for first time so mark it negative
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};