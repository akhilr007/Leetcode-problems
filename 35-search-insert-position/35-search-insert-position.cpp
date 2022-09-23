class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        int leftPointer = 0;
        int rightPointer = size - 1;
        
        int rightPosition = size;
        
        while(leftPointer <= rightPointer){
            
            int mid = leftPointer + (rightPointer - leftPointer) / 2;
            
            if(nums[mid] >= target){
                rightPosition = mid;
                rightPointer = mid - 1;
            }
            else{
                leftPointer = mid + 1;
            }
        }
        
        return rightPosition;
    }
};