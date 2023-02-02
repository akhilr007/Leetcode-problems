class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        bool flag = true;
        int n = words.size();
        
        unordered_map<char, int> mp;
        for(int i=0; i<order.length(); i++)
            mp[order[i]] = i;
        
        for(int i=0; i<n-1; i++){
            
            string cur = words[i];
            string nxt = words[i+1];
            
            int m = cur.length();
            int n = nxt.length();
            
            int minLen = min(m, n);
            int val1=0, val2=0;
            
            for(int j=0; j<minLen; j++){
                
                char ch1 = cur[j];
                char ch2 = nxt[j];
                
                val1 += ch1-'a';
                val2 += ch2-'a';
                
                if(ch1 == ch2)
                    continue;
                
                if(mp[ch1] > mp[ch2])
                    return false;
                else
                    break;
                
            }
            
            if(val1 == val2 && n < m) return false;
        }
        
        return true;
    }
};