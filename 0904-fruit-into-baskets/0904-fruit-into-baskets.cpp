class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        
        int i=0;
        int j=0;
        unordered_map<int, int> mp;
        
        int res=0;
        int total=0;
        
        while(j<n){
            
            mp[fruits[j]]++;
            total++;
        
            if(mp.size() <=2){
                res = max(res, total);
                j++;
                continue;
            }
            
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    total--;
                    if(mp[fruits[i]] == 0)
                        mp.erase(fruits[i]);
                    i++;
                }
                
                j++;
            }
        }
        
        return res;
    }
};