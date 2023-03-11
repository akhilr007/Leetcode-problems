class Solution {
public:
    // time complexity -> O(n log(sum - max + 1)) space complexity -> O(1)
    /*
    
    agar k = nums.size()
    to largest sum of any subarray max_element of individual element hoga
    
    high = sum of all elements hoga
    */
    int numberOfSubarraysByKeepingLimit(vector<int>& nums, int max_sum, int k){
        
        int cnt=1;
        int sum=0;
        for(auto& x: nums){
            
            if(sum + x <= max_sum){
                sum += x;
            }
            else{
                sum=x;
                cnt++;
            }
        }
        
        return cnt;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int low = *max_element(begin(nums), end(nums));
        int high = accumulate(begin(nums), end(nums), 0);
        
        int ans = high;
        
        while(low <= high){
            
            int mid = (low + high) /2 ;
            
            if(numberOfSubarraysByKeepingLimit(nums, mid, k) <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};