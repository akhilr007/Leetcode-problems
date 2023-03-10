class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = INT_MAX;
        
        int i=0;
        int j=0;
        
        int sum = 0;
        
        while(j < n){
            
            sum += nums[j];
            
            if(sum < target)
                j++;
            
            if(sum >= target){
                
                int len = j-i+1;
                ans = min(ans, len);

                while(sum >= target){
                    
                    sum -= nums[i];
                    i++;
                    
                    if(sum >= target){
                        int len = j-i+1;
                        ans = min(ans, len);
                    }
                    
                }
                j++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};