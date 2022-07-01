class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int nsl[n];
        
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.size() == 0){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top();
            }
            st.push(i);
        }
        
        int nsr[n];
        while(st.size()>0) st.pop();
        
        for(int i=n-1; i>=0; i--){
            
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.size() == 0){
                nsr[i] = n;
            }
            else{
                nsr[i] = st.top();
            }
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            
            int width = nsr[i] - nsl[i] - 1;
            int length = heights[i];
            
            int cur_area = length * width;
            
            maxArea = max(maxArea, cur_area);
        }
        
        return maxArea;
    }
};