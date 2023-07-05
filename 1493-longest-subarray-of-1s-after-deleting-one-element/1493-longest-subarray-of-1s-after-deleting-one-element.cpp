class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int result = 0;
        int zeroCount = 0;
        
        int i=0;
        for(int j=0; j<n; j++){
            
            if(nums[j] == 0)
                zeroCount++;
            
            while(zeroCount > 1){
                if(nums[i]==0)
                    zeroCount--;
                
                i++;
            }
            
            result = max(result, j-i);
        }
        return result;
    }
};