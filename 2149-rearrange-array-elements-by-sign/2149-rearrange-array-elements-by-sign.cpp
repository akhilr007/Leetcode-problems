class Solution {
public:
    vector<int> brute(vector<int>& nums){
        
        int n = nums.size();
        
        vector<int> pos, neg;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        
        vector<int> ans(n);
        for(int i=0; i<n/2; i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        
        return ans;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        return brute(nums);    
    }
};