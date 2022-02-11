class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int si=0;
        int ei=0;
        
        int ans=0;
        int prev_count=0;
        
        while(ei < nums.size()){
            
            if(left <= nums[ei] && nums[ei] <= right){
                // no of subarrays that ends at ei -> prev count
                prev_count = ei-si+1;
                // add the prev_count to actual ans that we havev
                ans += prev_count;
            }
            else if(nums[ei] < left){
                ans += prev_count;
            }
            else if(right < nums[ei]){
                si = ei+1;
                prev_count=0;
            }
            ei++;
        }
        return ans;
    }
};