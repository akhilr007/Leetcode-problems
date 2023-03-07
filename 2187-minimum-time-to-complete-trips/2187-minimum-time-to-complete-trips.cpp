class Solution {
private:
    long long bruteForce(vector<int>& time, int totalTrips){
        
        long long minTime=1;
        
        while(minTime){
            
            long long trips = 0;
            for(int i=0; i<time.size(); i++){
                
                trips += (minTime / time[i]);
            }
            
            if(trips >= totalTrips)
                return minTime;
            minTime++;
        }
        return -1;
    }
public:
    long long tripsTaken(vector<int>& time, long long unit){
        
        long long cnt=0;
        for(auto& t: time){
            cnt += (unit/t);
        }
        
        return cnt;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long low = 1, high = 1e14;
        long long ans = high;
        
        while(low <= high){
            
            long long mid = low + (high - low)/2;
            
            if(tripsTaken(time, mid) >= totalTrips){
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