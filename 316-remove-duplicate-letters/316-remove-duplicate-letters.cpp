class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        vector<bool> visit(26, false);
        vector<int> lastIndex(26, 0);
        
        // 1. set last indexes for every char
        for(int i=0; i<n; i++){
            lastIndex[s[i]-'a'] = i;
        }
        
        stack<char> st;
        
        // 2. iterate over string s
        for(int i=0; i<n; i++){
            
            if(visit[s[i]-'a']) continue;
            
            visit[s[i] - 'a'] = true;
            
            while(st.size()>0 && (st.top() > s[i]) && lastIndex[st.top()-'a'] > i){
                char ch = st.top();
                st.pop();
                visit[ch-'a'] = false;
            }
            
            st.push(s[i]);
        }
        
        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};