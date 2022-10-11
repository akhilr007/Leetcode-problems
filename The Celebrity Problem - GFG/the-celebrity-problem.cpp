//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i=0; i<M.size(); i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            
            int i = st.top();
            st.pop();
            
            int j = st.top();
            st.pop();
            
            if(M[i][j] == 1){
                // i knows j so i will not be celebrity
                st.push(j);
            }
            else if(M[j][i] == 1){
                // j knows i, so j will not be celebrity
                st.push(i);
            }
        }
        
        int potentialCelebrity = st.top();
        
        for(int i=0; i<M.size(); i++){
            if(potentialCelebrity == i) continue;
            if(M[potentialCelebrity][i] == 1 || M[i][potentialCelebrity] == 0){
                return -1;
            }
        }
        
        return potentialCelebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends