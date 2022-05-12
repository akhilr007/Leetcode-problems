class Solution {
public:
    void permute(int index, vector<int>& nums, vector<vector<int>>& ans){
        
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i=index; i<nums.size(); i++){
            
            if(s.find(nums[i]) != s.end()) continue;
            
            s.insert(nums[i]);
            swap(nums[index], nums[i]);
            permute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        permute(0, nums, ans);
        return ans;
    }
};