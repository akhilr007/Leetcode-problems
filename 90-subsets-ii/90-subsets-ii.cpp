class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset){
        if(ind >= nums.size()){
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[ind]);
        helper(ind+1, nums, res, subset);
        
        
        //exclude
        subset.pop_back();
        while(ind+1 < nums.size() and nums[ind] == nums[ind+1]) ind++;
        helper(ind+1, nums, res, subset);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> subset;
        helper(0, nums, res, subset);
        return res;
    }
};