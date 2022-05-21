class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = 0, i=0;
        for(i=0; i<nums.size(); i++){
            result ^= nums[i];
            result ^= i;
        }
        
        result ^= i;
        return result;
    }
};