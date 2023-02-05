class Solution {
public:
    bool areEqual(vector<int>&phash, vector<int>&shash){
        
        for(int i=0; i<26; i++){
            if(phash[i] != shash[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        if(p.length() > s.length())
            return {};
        
        vector<int> shash(26, 0), phash(26, 0);
        
        for(int i=0; i<p.length(); i++){
            phash[p[i]-'a']++;
        }
        
        vector<int> res;
        int i=0;
        int j=0;
        
        while(j < s.length()){
            
            shash[s[j]-'a']++;
            if(j-i+1 < p.length()){
                j++;
                continue;
            }
            
            if(j-i+1 == p.length()){
                if(areEqual(phash, shash)){
                    res.push_back(i);
                }
                j++;
            }
            else{
                shash[s[i]-'a']--;
                
                i++;
                if(areEqual(phash, shash)){
                    res.push_back(i);
                }
                j++;
            }
        }
        
        return res;
    }
};