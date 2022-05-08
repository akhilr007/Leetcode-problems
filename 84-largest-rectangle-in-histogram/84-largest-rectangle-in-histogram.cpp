class Solution{
public:
    vector<int> nextSmallerToLeft(vector<int>& heights){

        int n=heights.size();
        vector<int> nsl(n);

        stack<int> st;

        nsl[0] = -1;
        st.push(0);

        for(int i=1; i<heights.size(); i++){

            while(st.size()>0 and heights[st.top()] >= heights[i]){
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

        return nsl;
    }

    vector<int> nextSmallerToRight(vector<int>& heights){

        int n=heights.size();
        vector<int> nsr(n);

        stack<int> st;

        nsr[n-1] = n;
        st.push(n-1);

        for(int i=n-2; i>=0; i--){

            while(st.size()>0 and heights[st.top()] >= heights[i]){
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

        return nsr;
    }

    int largestRectangleArea(vector<int>& heights){

        vector<int> nsl = nextSmallerToLeft(heights);
        vector<int> nsr = nextSmallerToRight(heights);

        int maxArea=0;
        for(int i=0; i<heights.size(); i++){
            
            int height = heights[i];
            int width = nsr[i] - nsl[i] - 1;

            maxArea = max(height*width, maxArea);
        }

        return maxArea;

    }
};