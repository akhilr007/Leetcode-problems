class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int, int> mp;
        
        int mini=INT_MAX;
        for(auto el : deck){
            mp[el]++;
        }
        
        for(auto it : mp){
            mini = min(mini, it.second);
        }
        
        if(mini < 2) return false;
        
        for(int x=2; x<=mini; x++){
            
            bool flag = true;
            
            for(auto it : mp){
                
                int val = it.second;
                
                if(val % x != 0){
                    flag = false;
                    break;
                }
            }
            
            if(flag) return true;
        }
        
        return false;
    }
};