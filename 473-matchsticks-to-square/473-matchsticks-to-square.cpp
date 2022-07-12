class Solution {
public:
    bool helper(vector<int>& matchsticks, int i, int subsetSum, int target, int k, vector<bool>& vis){
        
        if(k == 0) return true;
        if(subsetSum == target){
            return helper(matchsticks, 0, 0, target, k-1, vis);
        }
        
        for(int j=i; j<matchsticks.size(); j++){
            if(vis[j] or matchsticks[j] + subsetSum > target) continue;
            
            vis[j] = true;
            if(helper(matchsticks, j+1, subsetSum + matchsticks[j], target, k, vis)){
                return true;
            }
            vis[j] = false;
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        int sum=0;
        for(auto x : matchsticks) sum += x;
        
        int target = sum / 4;
        
        if(sum % 4 != 0) return false;
        for(auto x : matchsticks){
            if(x > target) return false;
        }
        
        vector<bool> vis(matchsticks.size(), false);
        return helper(matchsticks, 0, 0, target, 4, vis);
    }
};