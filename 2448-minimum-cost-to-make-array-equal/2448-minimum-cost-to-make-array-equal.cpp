class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int target){
        
        long long result = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            result += (long long)abs(nums[i]-target) * cost[i];
        }
        return result;
    }
    
    long long brute(vector<int>& nums, vector<int>& cost){
        
        long long result = LONG_MAX;
        
        for(int i=0; i<nums.size(); i++){
            
            result = min(result, findCost(nums, cost, nums[i]));
        }
        return result;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int left = INT_MAX;
        int right = INT_MIN;
        
        /* FIND MIN AND MAX*/
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] < left){
                left = nums[i];
            }
            
            if(nums[i] > right){
                right = nums[i];
            }
        }
        
        long long result = INT_MAX;
        
        while(left <= right){
            
            int mid = left + (right - left) / 2;
            
            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid+1);
            
            result = min(cost1, cost2);
            
            if(cost2 > cost1){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};