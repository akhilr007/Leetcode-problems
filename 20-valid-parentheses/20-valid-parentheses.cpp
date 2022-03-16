class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                
                if(s[i] == ')'){
                    
                    if(st.size() == 0 || st.top() != '(') return false;
                }
                
                else if(s[i] == '}'){
                    
                    if(st.size() == 0 || st.top() != '{') return false;
                }
                
                else if(s[i] == ']'){
                    
                    if(st.size() == 0 || st.top() != '[') return false;
                }
                
                st.pop();
            }
        }
        
        if(st.size()>0) return false;
        else return true;
        
    }
};