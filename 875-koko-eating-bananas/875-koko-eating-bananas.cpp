class Solution {
public:
    
    bool isPossible(vector<int>& piles, int sp, int h){
        
        int total_time=0;
        
        for(int i=0; i<piles.size(); i++){
            
            int div = piles[i]/sp;
            
            total_time += div;
            
            if(piles[i]%sp != 0) total_time++;
        }
        
        return total_time <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi=piles[0];
        
        for(auto val : piles){
            maxi = max(val, maxi);
        }
        
        if(h == piles.size()){
            return maxi;
        }
        
        int lo = 1;
        int hi = maxi;
        
        int ans=0;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(isPossible(piles, mid, h) == true){
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