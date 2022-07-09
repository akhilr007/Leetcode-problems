class Solution {
private:
    int f(int i, vector<int>& nums, int k, int n, vector<int>& dp){
        
        if(i >= n) return INT_MIN;
        if(i == n-1){
            return nums[i];
        }
        
        if(dp[i] != -1) return dp[i];
        
        int ans=INT_MIN;
        for(int j=i+1; j<=min(i+k, n-1); j++){
            ans =  max(ans, nums[i] + f(j, nums, k, n, dp));
        }
        
        return dp[i] = ans;
    }
    
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> d;
        d.push_back(0);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for(int i=1; i<n; i++){
            if(d.front() + k < i) d.pop_front();
            
            dp[i] = nums[i] + dp[d.front()];
            
            while(!d.empty() && dp[d.back()] <= dp[i]){
                d.pop_back();
            }
            d.push_back(i);
        }
        
        return dp[n-1];
        
    }
};