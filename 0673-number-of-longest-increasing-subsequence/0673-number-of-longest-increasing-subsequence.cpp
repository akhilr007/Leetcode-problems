class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, 1), count(n, 1);
        
        int maxi = 0;
        for(int index=0; index<n; index++){
            
            for(int prev_index=0; prev_index<index; prev_index++){
                
                if(nums[index] > nums[prev_index]){
                    
                    if(1 + dp[prev_index] > dp[index]){
                        
                        dp[index] = 1 + dp[prev_index];
                        count[index] = count[prev_index];
                        
                    }
                    else if(1 + dp[prev_index] == dp[index]){
                        count[index] += count[prev_index];
                    }
                }
            }

            maxi = max(dp[index], maxi);
        }
        
        int result = 0;
        for(int i=0; i<n; i++){
            
            if(dp[i] == maxi)
                result += count[i];
        }
        
        return result;
    }
};