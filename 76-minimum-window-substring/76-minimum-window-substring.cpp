class Solution {
public:
    string minWindow(string s, string t) {
        
        int count=0;
        int m[256] = {0};
        
        for(int i=0; i<t.length(); i++){
            if(m[t[i]] == 0) count++;
            m[t[i]]++;
        }
        
        int i=0;
        int j=0;
        int res=INT_MAX;
        int start=0;
        
        while(j<s.length()){
            
            m[s[j]]--;
            
            if(m[s[j]] == 0) count--;
            
            if(count == 0){
                
                while(count==0){
                    if(res > j-i+1){
                        res = j-i+1;
                        start = i;
                    }
                    
                    m[s[i]]++;
                    if(m[s[i]] == 1) count++;
                    i++;
                }
            }
            j++;
        }
        
        if(res == INT_MAX) return "";
        return s.substr(start, res);
    }
};