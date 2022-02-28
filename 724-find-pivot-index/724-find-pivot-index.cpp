class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
//         int n=nums.size();
        
//         vector<int> lsum(n);
//         vector<int> rsum(n);
        
//         for(int i=0; i<n; i++){
//             if(i==0) lsum[i]=nums[i];
//             else lsum[i] = lsum[i-1] + nums[i];
//         }
        
//         for(int i=n-1; i>=0; i--){
//             if(i==n-1) rsum[i] = nums[i];
//             else rsum[i] = rsum[i+1] + nums[i];
//         }
        
//         int pivotIndex=-1;
        
//         for(int i=0;i<n; i++){
            
//             if(i==0 && rsum[i+1]==0) return i;
            
//             else if(i==n-1 && lsum[i-1]==0) return i;
            
//             else if( (i!=0 && i!=n-1) && (lsum[i-1]==rsum[i+1]) ) {
//                 return i;
//             }
//         }
        
//         return pivotIndex;
        
        int n=nums.size();
        
        int sum=0;
        for(auto val : nums) sum += val;
        
        int lsum=0;
        int rsum=sum;
        
        for(int i=0; i<n; i++){
            rsum = rsum-nums[i];
            
            if(lsum == rsum) return i;
            
            lsum += nums[i];
        }
        
        return -1;
    }
};