class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        int leftSum = 0;
        int totalSum = 0;
        
        for(auto num: nums)
            totalSum += num;
        
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            totalSum -= nums[i];
            result.push_back(abs(leftSum - totalSum));
            leftSum += nums[i];
        }
        
        return result;
    }
};