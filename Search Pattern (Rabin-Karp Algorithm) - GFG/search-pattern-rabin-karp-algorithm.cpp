// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string p, string t)
        {
            long power = 31;
            long p_ = 31;
            long pHash = p[0]-'a'+1;
            long mod = 1e9+7;
            
            for(int i=1; i<p.length(); i++){
                pHash = (pHash + (p[i]-'a'+1)*power)%mod;
                power = (power*p_)%mod;
            }
            
            //rabin karp alogorithm implementation
            vector<long> dp(t.length());
            vector<long> pi(t.length()); // storing power like p0, p1, p2
            
            power = p_;
            dp[0] = t[0]-'a'+1;
            pi[0] = 1;
            
            for(int i=1; i<t.length(); i++){
                
                dp[i] = (dp[i-1] + (t[i]-'a'+1)*power)%mod;
                pi[i] = power;
                power = (power*p_)%mod;
            }
            
            vector<int> ans;
            int sp=0;
            int ep=p.length()-1;
            
            while(ep<t.length()){
                long curWin = dp[ep];
                if(sp>0) curWin = (curWin - dp[sp-1] + mod)%mod;
                if(curWin == (pHash*pi[sp])%mod){
                    ans.push_back(sp+1);
                }
                sp++;
                ep++;
            }
            
            if(ans.size()==0){
                vector<int> v;
                v.push_back(-1);
                return v;
            }
            
            return ans;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends