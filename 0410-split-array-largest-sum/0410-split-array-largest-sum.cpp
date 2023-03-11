class Solution {
public:
    bool isEligible(vector<int>& nums, int max_sum, int k){
        
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
        
        return cnt <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int low = *max_element(begin(nums), end(nums));
        int high = accumulate(begin(nums), end(nums), 0);
        
        int ans = high;
        
        while(low <= high){
            
            int mid = (low + high) /2 ;
            
            if(isEligible(nums, mid, k)){
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