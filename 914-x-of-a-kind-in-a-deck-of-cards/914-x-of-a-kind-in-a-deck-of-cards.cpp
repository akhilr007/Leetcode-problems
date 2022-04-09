class Solution {
public:
    int gcd(int a, int b){
        
        if(b == 0) return a;
        
        return gcd(b, a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int, int> mp;
        
        for(auto val : deck){
            mp[val]++;
        }
        
        int ans=0;
        for(auto it : mp){
            
            int val = it.second;
            ans = gcd(ans, val);
        }
        
        return ans >= 2;
    }
};