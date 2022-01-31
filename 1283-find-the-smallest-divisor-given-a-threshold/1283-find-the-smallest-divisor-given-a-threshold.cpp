class Solution {
public:
    
    bool isPossible(vector<int>& nums, int mid, int threshold){
        
        int tt=0;
        
        for(auto val : nums){
            
            int div = val / mid;
            
            tt += div;
            
            if(val%mid != 0) tt++;
        }
        
        return tt <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maxi = nums[0];
        
        for(auto val : nums){
            maxi = max(val, maxi);
        }
        
        if(threshold == nums.size()){
            return maxi;
        }
        
        int lo = 1;
        int hi = maxi;
        
        int ans = 0;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(isPossible(nums, mid, threshold) == true){
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