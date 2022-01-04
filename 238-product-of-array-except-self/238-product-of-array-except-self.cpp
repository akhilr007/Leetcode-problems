class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> res(n);
        
        int left=1;
        
        for(int i=0; i<n; i++){
            
            if(i>0){
                left *= nums[i-1];
            }
            res[i] = left;
        }
        
        int right=1;
        for(int i=n-1; i>=0; i--){
            if(i<n-1){
                right = right * nums[i+1];
            }
            
            res[i] *= right;
        }
        
        return res;
        
//         vector<int> res(n);
        
//         // prefix of left product array
//         vector<int> left(n);
//         left[0] = nums[0];
        
//         for(int i=1; i<n; i++){
//             left[i] = left[i-1] * nums[i];
//         }
        
//         //prefix of right product array
//         vector<int> right(n);
//         right[n-1] = nums[n-1];
        
//         for(int i=n-2; i>=0; i--){
//             right[i] = right[i+1] * nums[i];
//         }
        
//         for(int i=0; i<n; i++){
//             if(i==0){
//                 res[i] = right[i+1];
//                 continue;
//             }
//             if(i==n-1){
//                 res[i] = left[i-1];
//                 continue;
//             }
            
//             res[i] = left[i-1] * right[i+1];
//         }
        
//         return res;
    }
};