class Solution {
public:
    
    vector<int> findNextSmallerLeft(vector<int>& heights){
        
        int n=heights.size();
        vector<int> nsl(n);
        
        stack<int> st;
        nsl[0]=-1;
        st.push(0);
        
        for(int i=1; i<heights.size(); i++){
            
            while(st.size()>0 and heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.size() ==0){
                nsl[i]=-1;
            }
            else{
                nsl[i] = st.top();
            }
            
            st.push(i);
        }
        
        return nsl;
    }
    
    vector<int> findNextSmallerRight(vector<int>& heights){
        
        int n=heights.size();
        vector<int> nsr(n);
        
        stack<int> st;
        nsr[n-1]=n;
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            
            while(st.size()>0 and heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.size() ==0){
                nsr[i]=n;
            }
            else{
                nsr[i] = st.top();
            }
            
            st.push(i);
        }
        
        return nsr;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nsl = findNextSmallerLeft(heights);
        vector<int> nsr = findNextSmallerRight(heights);
        
        int area=0;
        for(int i=0; i<heights.size(); i++){
            int width = (nsr[i]-nsl[i])-1;
            int height = heights[i];
            
            area = max(area, width*height);
        }
        
        return area;
    }
};