class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char,int> mp;
        int n=s.length();
        
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        
        int prev = -1;
        int maxImpact = INT_MIN;
        
        vector<int> res;
        
        for(int i=0; i<n; i++){
            
            maxImpact = max(maxImpact , mp[s[i]]);
            
            if(maxImpact == i){
                int p = maxImpact - prev;
                res.push_back(p);
                prev = maxImpact;
            }
        }
        
        return res;
    }
};