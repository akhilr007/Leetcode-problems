class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>> &dp){
        
        if(ind == n){
            return 0;
        }
        
        if(dp[ind][prev_ind+1] != -1){
            return dp[ind][prev_ind+1];
        }
        
        // not take len
        int notTake = 0 + f(ind+1, prev_ind, nums, n, dp);
        int take=0;
        if(prev_ind == -1 or nums[ind] > nums[prev_ind]){
            take = 1 + f(ind+1, ind, nums, n, dp);
        }
        
        return dp[ind][prev_ind+1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return f(0, -1, nums, n, dp); // ind prev_index arr size of arr
        
//         vector<int> dp(n, 1);
//         int maxi=0;
        
//         for(int ind=0; ind<n; ind++){
            
//             for(int prev_ind=0; prev_ind<ind; prev_ind++){
                
//                 if(nums[prev_ind] < nums[ind]){
                    
//                     dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
//                 }
//             }
//             maxi = max(maxi, dp[ind]);
//         }
        
//         return maxi;
        
        if(nums.size()==0) return 0;
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        
        return temp.size();
    }
};