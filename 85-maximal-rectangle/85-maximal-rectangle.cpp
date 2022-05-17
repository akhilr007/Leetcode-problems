class Solution {
public:
    
    vector<int> nsl(vector<int>& v){
        
        int n=v.size();
        stack<int> st;
        st.push(0);
        
        vector<int> left(n);
        left[0] = -1;
        
        for(int i=1; i<n; i++){
            
            while(st.size()>0 && v[st.top()] >= v[i]){
                st.pop();
            }
            
            if(st.size()==0){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        return left;
    }
    
    vector<int> nsr(vector<int>& v){
        
        int n=v.size();
        stack<int> st;
        st.push(n-1);
        
        vector<int> right(n);
        right[n-1] = n;
        
        for(int i=n-2; i>=0; i--){
            
            while(st.size()>0 && v[st.top()] >= v[i]){
                st.pop();
            }
            
            if(st.size()==0){
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }
            
            st.push(i);
        }
        
        return right;
    }
    
    int maxRectangle(vector<int>& v){
        
        vector<int> left = nsl(v);
        vector<int> right = nsr(v);
        
        int maxArea=0;
        
        for(int i=0; i<v.size(); i++){
            
            int height = v[i];
            int width = right[i] - left[i] - 1;
            
            maxArea = max(maxArea, height*width);
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> v;
        
        for(int j=0; j<matrix[0].size(); j++){
            int val = matrix[0][j]-'0';
            v.push_back(val);
        }
        
        int mx=0;
        mx = max(mx, maxRectangle(v));
        
        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] += 1;
                }
            }
            
            mx = max(mx, maxRectangle(v));
        }
        
        return mx;
    }
};