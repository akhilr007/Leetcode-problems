class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
        int j=n-1;
        int k=n-1;
        
        vector<int> ans(n, 0);
        while(i<=j){
            
            if(abs(nums[i]) >= abs(nums[j])){
                ans[k] = (long)(nums[i]*nums[i]);
                i++;
            }
            else{
                ans[k] = (long)(nums[j]*nums[j]);
                j--;
            }
            k--;
        }
        
        return ans;
        
    }
};