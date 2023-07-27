class Solution {
public:
    bool isPossible(vector<int>& batteries, long long mid, int n){
        
        long long target = mid * n;
        long long totalMins=0;
        for(int i=0; i<batteries.size(); i++){
            
            totalMins += min((long long)batteries[i], mid);
            if(totalMins >= target)
                return true;
        }
        
        return totalMins >= target;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long l=1e9, r=0;
        for(int i=0; i<batteries.size(); i++){
            if(batteries[i]<=l)
                l = batteries[i];
            r += batteries[i];
        }
        
        r = r / n;
        
        long long result = 0;
        while(l<=r){
            
            long long mid = l + (r-l)/2;
            
            if(isPossible(batteries, mid, n)){
                result = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return result;
    }
};