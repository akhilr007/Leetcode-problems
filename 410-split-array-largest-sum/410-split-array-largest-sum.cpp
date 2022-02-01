class Solution {
public:
    
    bool isPossible(vector<int>& nums, int mid, int m){
        
        int subarray_ct=1;
        int sum=0;
        
        for(auto val : nums){
            
            sum += val;
            
            if(sum > mid){
                subarray_ct++;
                sum = val;
            }
        }
        
        return subarray_ct <= m;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int maxi = nums[0];
        int sum = 0;
        
        for(auto val : nums){
            maxi = max(maxi, val);
            sum += val;
        }
        
        int lo = maxi;
        int hi = sum;
        
        int ans=0;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(isPossible(nums, mid, m) == true){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};