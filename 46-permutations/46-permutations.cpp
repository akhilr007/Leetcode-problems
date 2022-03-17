class Solution {
public:
    void permute(vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums, int freq[]){
        
        if(ds.size() == nums.size()){
            
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            
            if(!freq[i]){
                
                ds.push_back(nums[i]);
                freq[i] = 1;
                permute(ds, ans, nums, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int n=nums.size();
        int freq[n];
        for(int i=0; i<n; i++) freq[i] = 0;
        
        permute(ds, ans, nums, freq);
        
        return ans;
    }
};