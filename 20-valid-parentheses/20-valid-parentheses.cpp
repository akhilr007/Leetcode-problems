class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            
            // check for open brackets
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            
            else if(ch == ')' || ch == ']' || ch == '}'){
                
                if(ch == ')'){
                    if(st.size()==0 || st.top() != '('){
                        return false;
                    }
                }
                
                else if(ch == '}'){
                    if(st.size()==0 || st.top() != '{'){
                        return false;
                    }
                }
                
                else if(ch == ']'){
                    if(st.size()==0 || st.top() != '['){
                        return false;
                    }
                }
                
                st.pop();
            }
            
        }
        
        
        if(st.size()>0) return false;
        else return true;
        
    }
};