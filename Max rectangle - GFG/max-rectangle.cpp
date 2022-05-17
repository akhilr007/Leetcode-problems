// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    vector<int> nsl(vector<int>& v){
        
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
                nsl[i] =-1;
            }
            else{
                nsl[i] = st.top();
            }
            st.push(i);
        }
        
        return nsl;
    }
  
    vector<int> nsr(vector<int>& v){
        
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
  
    int maxAreaHistogram(vector<int>& v){
        
        vector<int> right = nsr(v);
        vector<int> left = nsl(v);
        
        int maxArea=0;
        for(int i=0; i<v.size(); i++){
            
            int height = v[i];
            int width = right[i]-left[i]-1;
            
            maxArea = max(maxArea, height*width);
        }
        
        return maxArea;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        vector<int> v;
        for(int j=0; j<m; j++){
            v.push_back(M[0][j]);
        }
        
        int mx=0;
        mx = max(mx, maxAreaHistogram(v));
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(M[i][j] == 0){
                    v[j] = 0;
                }
                else{
                    v[j] += M[i][j];
                }
            }
            
            mx = max(mx, maxAreaHistogram(v));
        }
        
        return mx;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends