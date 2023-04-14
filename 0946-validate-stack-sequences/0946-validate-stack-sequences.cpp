class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        stack<int> st;
        
        int i=0;
        int j=0;
        
        while(i<n && j<n){
            
            st.push(pushed[i]);
            while(j<n && !st.empty() && popped[j] == st.top()){
                st.pop();
                j++;
            }
            i++;
        }
        
        return st.empty();
    }
};