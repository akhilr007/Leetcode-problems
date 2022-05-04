class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int count=0;
        
        for(int i=0; i<nums.size(); i++){
            
            int res = k-nums[i];
            
            if(mp.find(res) != mp.end()){
                count++;
                
                if(mp[res] == 1){
                    mp.erase(res);
                }
                else{
                    mp[res]--;
                }
            }
            
            else{
                mp[nums[i]]++;
            }
            
        }
        
        return count;
    }
};