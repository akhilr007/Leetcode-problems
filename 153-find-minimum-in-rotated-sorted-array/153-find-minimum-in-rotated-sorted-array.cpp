class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int lo=0;
        int hi=nums.size()-1;
        
        if(nums[0] <= nums[hi]) return nums[0];
        
        while(lo<=hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            
            else if(nums[mid-1] > nums[mid]){
                return nums[mid];
            }
            
            if(nums[lo] <= nums[mid]){
                lo = mid+1;
            }
            else if(nums[mid] <= nums[hi]){
                hi = mid-1;
            }
        }
        
        return -1;
    }
};