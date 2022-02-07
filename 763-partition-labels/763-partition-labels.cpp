class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int mp[26];;
        int n=s.length();
        
        for(int i=0; i<n; i++){
            mp[s[i]-'a'] = i;
        }
        
        int prev = -1;
        int maxImpact = INT_MIN;
        
        vector<int> res;
        
        for(int i=0; i<n; i++){
            
            maxImpact = max(maxImpact , mp[s[i]-'a']);
            
            if(maxImpact == i){
                int p = maxImpact - prev;
                res.push_back(p);
                prev = maxImpact;
            }
        }
        
        return res;
    }
};