class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int count=0;
        
        stack<pair<char, int>> st;
        
        for(int i=0; i<s.length(); i++){
            
            char ch = s[i];
            
            if(st.size()==0){
                st.push({ch, 1});
            }
            
            else if(ch != st.top().first){
                st.push({ch, 1});

            }
            
            else if(ch == st.top().first){
                st.push({ch, st.top().second+1});
                
                if(st.top().second == k){
                    
                    int freq = st.top().second;
                    while(freq-->0){
                        st.pop();
                    }
                }
            }
        }
        
        string res="";
        while(st.size()>0){
            res += st.top().first;
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};