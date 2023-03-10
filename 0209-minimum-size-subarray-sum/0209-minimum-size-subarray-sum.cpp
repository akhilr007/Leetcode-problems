class Solution {
public:
    
    bool maxSubarrayOfSizeK(vector<int>& nums, int k, int target){
        
        int sum=0;
        int j;
        for(j=0; j<k; j++){
            sum += nums[j];
        }
        
        if(sum >= target)
            return true;
        
        int i=0;
        while(j<nums.size()){
            
            sum += nums[j] - nums[i];
            j++;
            i++;
            
            if(sum >= target)
                return true;
        }
        
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 1;
        int high = n;
        
        int ans = n+1;
        
        while(low <= high){
            
            int mid = (low + high) / 2;
            
            if(maxSubarrayOfSizeK(nums, mid, target)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans == n+1 ? 0 : ans;
    }
};