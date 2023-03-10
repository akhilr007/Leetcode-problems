class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            
            // peak can be in left till mid
            if(nums[mid] > nums[mid+1])
                high = mid;
            // peak can be in right
            else
                low = mid + 1;
        }
        
        return low;
    }
};