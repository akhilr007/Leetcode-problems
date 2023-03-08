class Solution {
public:
    int timeTakenToEatBananas(vector<int>& piles, int k){
        
        long long cnt=0;
        for(auto& pile: piles){
            cnt += (pile / k) ;
            
            if(pile % k != 0) cnt++;
        }
        
        return (int)cnt;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        
        int low = 1;
        int high = 1e9;
        
        if(h == high)
            return piles.size();
        
        int ans = high;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            if(timeTakenToEatBananas(piles, mid) <= h){
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