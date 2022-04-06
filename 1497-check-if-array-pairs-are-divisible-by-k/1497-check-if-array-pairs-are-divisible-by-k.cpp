class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int, int> mp; // rem -> count;
        
        for(auto el : arr){
            int rem = (el % k + k)%k;
            
            mp[rem]++;
        }
        
        for(auto el : arr){
            
            int rem = ((el % k) + k)%k;
            
            if(rem == 0){
                // then count of rem should be even
                if(mp[rem] % 2 != 0) return false;
            }
            else{
                if(mp[rem] != mp[k-rem]) return false;
            }
        }
        
        return true;
    }
};