class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();
        stack<char> st;
        
        for(int i=0; i<n; i++){
            
            char ch = s[i];
            if(ch != '*')
                st.push(ch);
            else{
                
                if(!st.empty()) st.pop();
            }
        }
        
        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(begin(res), end(res));
        return res;
    }
};