class Solution{
public:

    vector<int> nextSmallerLeft(vector<int>& v){
        
        int n=v.size();

        stack<int> st;
        st.push(0);

        vector<int> nsl(n);
        nsl[0] = -1;

        for(int i=1; i<n; i++){

            while(st.size()>0 && v[st.top()] >= v[i]){
                st.pop();
            }

            if(st.size()==0){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top();
            }

            st.push(i);
        }

        return nsl;
    }

    vector<int> nextSmallerRight(vector<int>& v){
        
        int n=v.size();

        stack<int> st;
        st.push(n-1);

        vector<int> nsr(n);
        nsr[n-1] = n;

        for(int i=n-2; i>=0; i--){

            while(st.size()>0 && v[st.top()] >= v[i]){
                st.pop();
            }

            if(st.size()==0){
                nsr[i] = n;
            }
            else{
                nsr[i] = st.top();
            }

            st.push(i);
        }

        return nsr;
    }

    int maximumAreaHistogram(vector<int>& v){

        vector<int> nsl = nextSmallerLeft(v);
        vector<int> nsr = nextSmallerRight(v);

        int maxArea=0;
        for(int i=0; i<v.size(); i++){
            int height = v[i];
            int width = nsr[i]-nsl[i]-1;

            int area = height*width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix){

        vector<int> v;
        for(int i=0; i<matrix[0].size(); i++){
            int val = matrix[0][i] - '0';
            v.push_back(val);
        }

        int mx = 0;
        mx = max(mx, maximumAreaHistogram(v));

        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] += 1;
                }
            }

            mx = max(mx, maximumAreaHistogram(v));
        }

        return mx;
    }
};