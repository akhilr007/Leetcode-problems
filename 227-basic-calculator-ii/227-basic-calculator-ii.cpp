class Solution {
public:
    int calculate(string s) {
        
        int temp=0;
        stack<int> st;
        
        char sign = '+';
        
        for(int i=0; i<s.length(); i++){
            
            if(isdigit(s[i])){
                temp = temp*10+(s[i]-'0');
            }
            
            if(!isdigit(s[i]) && !isspace(s[i]) || i==s.length()-1){
                
                if(sign == '+'){
                    st.push(temp);
                }
                else if(sign == '-'){
                    st.push(-temp);
                }
                else{
                    int num;
                    if(sign == '*'){
                        num = st.top()*temp;
                    }
                    else{
                        num = st.top()/temp;
                    }
                    
                    st.pop();
                    st.push(num);  
                }
                
                sign = s[i];
                temp = 0;
            }
        }
        
        int res=0;
        while(st.size()>0){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};