class Solution {
public:
    int lowerBound(vector<int>& nums, int target, int n){
        
        int lower_bound = n;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(nums[mid] >= target){
                lower_bound=mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return lower_bound;
    }
    
    int upperBound(vector<int>& nums, int target, int n){
        
        int upper_bound = n;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(nums[mid] > target){
                upper_bound = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return upper_bound;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int n = nums.size();
        
        int lb = lowerBound(nums, target, n);
        int ub = upperBound(nums, target, n);
        
        if(lb == n || nums[lb] != target)
            return {-1, -1};
        
        return {lb, ub-1};
    }
};