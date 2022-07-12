class Solution {
public:
    bool dfs(vector<int>& nums, int i, int k, int subsetSum, int target, vector<bool>& vis){
        
        if(k == 0) return true;
        if(subsetSum == target){
              return dfs(nums, 0, k-1, 0, target, vis);
        }
        
        for(int j=i; j<nums.size(); j++){
            if(vis[j] or subsetSum + nums[j] > target){
                continue;
            }
            
            vis[j] = true;
            if(dfs(nums, j+1, k, subsetSum+nums[j], target, vis)) return true;
            vis[j] = false;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        
        int target = sum / k;
        for(auto x : nums){
            if(x > target) return false;
        }
        
        if(sum % k != 0){
            return false;
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> vis(nums.size(), false);
        return dfs(nums, 0, k, 0, target, vis);
    }
};