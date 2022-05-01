class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] != '#'){
                st.push(s[i]);
            }
            else if(st.size() == 0 and s[i] == '#'){
                continue;
            }
            else if(st.size() > 0 and s[i] == '#'){
                st.pop();
            }
        }
        
        stack<char> ts;
        for(int i=0; i<t.length(); i++){
            if(t[i] != '#'){
                ts.push(t[i]);
            }
            else if(ts.size() == 0 and t[i] == '#'){
                continue;
            }
            else if(ts.size() > 0 and t[i] == '#'){
                ts.pop();
            }
        }
        
        if(st.size() == 0 and ts.size() == 0) return true;
        else if(st.size() != ts.size()) return false;
        
        while(st.size() > 0 and ts.size() > 0){
            char ch1 = st.top(); st.pop();
            char ch2 = ts.top(); ts.pop();
            
            if(ch1 != ch2) return false;
        }
        
        return true;
    }
};