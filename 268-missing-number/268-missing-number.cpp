class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int missingNumber=0;
        int i;
        for(i=0; i<nums.size(); i++){
            missingNumber ^= nums[i];
            missingNumber ^= i;
        }
        
        missingNumber ^= i;
        return missingNumber;
    }
};