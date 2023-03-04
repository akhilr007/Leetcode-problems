class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long res = 0;
        
        int minKPosition = -1;
        int maxKPosition = -1;
        int culpritIdx = -1;
        
        for(int i=0; i<nums.size(); i++){
            
            // find culprit index
            if(nums[i] < minK or nums[i] > maxK)
                culpritIdx = i;
            
            if(nums[i] == minK)
                minKPosition = i;
            
            if(nums[i] == maxK)
                maxKPosition = i;
            
            long long smaller = min(minKPosition, maxKPosition);
            
            long long temp = smaller - culpritIdx;
            
            res += temp <= 0 ? 0 : temp;
        }
        return res;
    }
};