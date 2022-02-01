class Solution {
public:
    
    bool isPossible(vector<int>& weights, int mid, int days){
        
        int no_of_days = 1;
        int sum = 0;
            
        for(auto val : weights){
            
            sum += val;
            
            if(sum > mid){
                no_of_days++;
                sum = val;
            }
        }
        
        return no_of_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxi = weights[0];
        int sum = 0;
        
        for(auto val : weights){
            maxi = max(maxi, val);
            sum += val;
        }
        
        int lo = maxi;
        int hi = sum;
        
        int ans = 0;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(isPossible(weights, mid, days) == true){
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