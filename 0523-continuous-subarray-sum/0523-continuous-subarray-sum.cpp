class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> remainder; // map remander -> end index
        remainder[0] = -1;
        
        int totalSum=0;
        for(int i=0; i<nums.size(); i++){
            
            totalSum += nums[i];
            int r = totalSum % k;
            
            if(remainder.find(r) == remainder.end()){
                remainder[r] = i;
            }
            else if(i - remainder[r] > 1) return true;
        }
        
        return false;
    }
};