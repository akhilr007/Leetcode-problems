class Solution {
public:
    
    pair<int, int> helper(vector<int>&heaters, int tar){
        
        int lo=0;
        int hi=heaters.size()-1;
        
        int js=-1;
        int jl=-1;
        
        while(lo<=hi){
            
            int mid = lo + (hi-lo)/2;
            
            if(heaters[mid] == tar){
                js=jl=heaters[mid];
                break;
            }
            
            else if(heaters[mid] > tar){
                jl=heaters[mid];
                hi = mid-1;
            }
            
            else if(heaters[mid] < tar){
                js=heaters[mid];
                lo = mid+1;
            }
        }
        
        pair<int, int> p;
        p.first = js;
        p.second = jl;
        
        return p;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        int maxi=0;
        
        for(int i=0; i<houses.size(); i++){
            
            pair<int, int> p = helper(heaters, houses[i]); // ceil and floor
            
            int ld = (p.first == -1 )? INT_MAX : houses[i] - p.first;
            int rd = (p.second == -1) ? INT_MAX : p.second - houses[i];
            
            maxi = max(maxi, min(ld, rd));
        }
        
        return maxi;
    }
};