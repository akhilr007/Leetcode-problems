class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        
        vector<bool> visit(26, false);
        vector<int> lastIndex(26, 0);
        
        for(int i=0; i<n; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        stack<char> st;
        for(int i=0; i<n; i++){
            
            char c = s[i];
            
            if(visit[c-'a']) continue;
            
            visit[c-'a'] = true;
            
            while(st.size() > 0 and (st.top() > s[i]) and lastIndex[st.top()-'a'] > i){
                char ch = st.top();
                st.pop();
                visit[ch-'a'] = false;
            }
            
            st.push(c);
        }
        
        string res="";
        
        while(st.size()>0){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};