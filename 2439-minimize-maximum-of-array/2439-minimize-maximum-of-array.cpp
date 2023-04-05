class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
     
        int n = nums.size();
        long long total = nums[0];
        int res = nums[0];
        
        for(int i=1; i<n; i++){
            
            total += nums[i];
            double avgSum = ceil(total * 1.0 / (i+1));
            res = max(res, (int)avgSum);
        }
        return res;
    }
};