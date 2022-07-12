class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int, int> m;
        for(auto x: deck){
            m[x]++;
        }
        
        int res = m[deck[0]];
        
        for(auto it : m){
            int val = it.second;
            if(val == 1) return false;
            
            res = gcd(max(res, val), min(res, val));
        }
        
        return res > 1? true : false;
    }
};