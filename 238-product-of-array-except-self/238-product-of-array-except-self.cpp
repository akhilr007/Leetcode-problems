class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /*
        worst case
        vector<int> res(nums.size(), 1);
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                
                if(i==j) continue;
                res[i] *= nums[j];
            }
            
        }
        
        return res;
        */
        
        // O(n)
        
        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = nums[0];
        
        for(int i=1; i<n; i++){
            left[i] = left[i-1]*nums[i];
        }
        
        right[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1]*nums[i];
        }
        
        vector<int> res(n);
        
        for(int i=0; i<n; i++){
            int ans = (i==0 ? 1 : left[i-1]) * (i==n-1?1:right[i+1]);
            res[i] = ans;
        }
        
        return res;
    }
};