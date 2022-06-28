class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(auto c: tokens){
            
            if(c == "+"){
                int v2 = st.top(); st.pop();
                int v1 = st.top(); st.pop();
                
                st.push(v1+v2);
            }
            else if(c == "-"){
                int v2 = st.top(); st.pop();
                int v1 = st.top(); st.pop();
                
                st.push(v1-v2);
            }
            else if(c == "*"){
                int v2 = st.top(); st.pop();
                int v1 = st.top(); st.pop();
                
                st.push(v1*v2);
            }
            else if(c == "/"){
                int v2 = st.top(); st.pop();
                int v1 = st.top(); st.pop();
                
                st.push(v1/v2);
            }
            else{
                st.push(stoi(c));
            }
        }
        
        return st.top();
    }
};