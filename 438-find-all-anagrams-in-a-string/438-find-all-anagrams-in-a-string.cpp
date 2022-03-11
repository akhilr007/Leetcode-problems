class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> v;
        unordered_map<char, int> m;
        
        for(int i=0; i<p.length(); i++) m[p[i]]++;
        
        int k=p.size();
        int count = m.size();
        
        int i=0, j=0;
        
        while(j < s.length()){
            
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0){
                    count--;
                }
            }
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
                
                if(count == 0) v.push_back(i);
                
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(m[s[i]] == 1) count++;
                }
                
                i++;
                j++;
            }
        }
        
        return v;
    }
};