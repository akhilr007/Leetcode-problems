class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> res(n);
        
        int left = 1;
        
        for(int i=0; i<n; i++){
            if(i>0){
                left = left*nums[i-1];
            }
            res[i] = left;
        }
        
        int right=1;
        for(int i=n-1; i>=0; i--){
            if(i<n-1){
                right = right*nums[i+1];
            }
            res[i] = res[i]*right;
        }
        
        return res;
        
    }
};