// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int isTrue, string& s, vector<vector<vector<int>>>& dp){
        
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                return s[i] == 'T';
            }
            else{
                return s[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        
        int ways=0;
        for(int ind = i+1; ind <= j-1; ind = ind+2){
            
            int lT = f(i, ind-1, 1, s, dp);
            int lF = f(i, ind-1, 0, s, dp);
            int rT = f(ind+1, j, 1, s, dp);
            int rF = f(ind+1, j, 0, s, dp);
            
            if(s[ind] == '&'){
                
                if(isTrue){
                    ways = (ways + (lT*rT));;
                }
                else{
                    ways = (ways + (lT*rF) + (lF*rT) + (lF*rF));
                }
            }
            
            else if(s[ind] == '|'){
                if(isTrue){
                    ways = (ways + (lT*rT)+ (lT*rF) + (lF*rT));
                }
                else{
                    ways = (ways + (lF*rF));
                }
            }
            
            else{
                
                if(isTrue){
                    ways = (ways + (lT*rF) + (lF*rT));
                }
                else{
                    ways = (ways + (lT*rT) + (lF*rF));
                }
            }
        }
        
        return dp[i][j][isTrue] = ways%1003;
    }
    
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (2, -1)));
        return f(0, N-1, 1, S, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends