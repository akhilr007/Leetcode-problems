class Solution {
public:
    int partitionString(string s) {
        
        int n = s.length();
        
        set<char> st;
        int i=0;
        
        int cnt=0;
        while(i<n){
            
            if(st.find(s[i]) != st.end()){
                cnt++;
                st.clear();
                continue;
            }
            
            st.insert(s[i]);
            i++;
        }
        
        if(st.size() > 0) cnt++;
        
        return cnt;
    }
};