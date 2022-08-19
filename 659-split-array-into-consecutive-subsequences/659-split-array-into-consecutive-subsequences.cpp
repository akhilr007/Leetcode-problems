class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int, int> fm, hm;
        for(auto x : nums){
            fm[x]++;
        }
        
        for(auto x : nums){
            
            if(fm[x] == 0) continue;
            
            else if(hm.find(x) != hm.end() && hm[x] > 0){
                hm[x]--;
                hm[x+1]++;
                fm[x]--;
            }
            else if(fm[x] > 0 && fm[x+1] > 0 && fm[x+2] > 0){
                fm[x]--;
                fm[x+1]--;
                fm[x+2]--;
                hm[x+3]++;
            }
            else return false;
        }
        
        return true;
    }
};