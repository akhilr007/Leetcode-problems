//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solveRec(int idx, int A[], int N){
        
        if(idx >= N-1) return true;
        
        for(int j=1; j<=A[idx]; j++){
            
            if(solveRec(idx + j, A, N)) return true;
        }
        
        return false;
    }
    
    int t[100001];
    int solveMem(int idx, int A[], int N){
        
        if(idx >= N-1) return true;
        if(t[idx] != -1) return t[idx];
        
        for(int j=1; j<=A[idx]; j++){
            
            if(solveMem(idx + j, A, N)) return t[idx] = true;
        }
        
        return t[idx] = false;
    }
    
    int solveTab(int A[], int N){
        
        vector<int> dp(N, 0);
        dp[0] = 1;
        
        for(int i=1; i<N; i++){
            
            for(int j=i-1; j>=0; j--){
                
                if(dp[j] == 1 &&  j + A[j] >= i) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[N-1];
    }
    
    int solveOptimal(int A[], int N){
        
        int maxReachable = 0;
        for(int i=0; i<N; i++){
            
            if(i > maxReachable) return false;
            maxReachable = max(maxReachable, i + A[i]);
        }
        
        return true;
    }
    
    int canReach(int A[], int N) {
        // code here
        return solveOptimal(A, N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends