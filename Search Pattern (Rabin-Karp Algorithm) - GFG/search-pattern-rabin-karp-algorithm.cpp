// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
public:
    vector <int> search(string pat, string txt)
    {


        long power = 31; // prime number
        long p=31;
        long patHash = pat[0]-'a'+1;
        long mod = 1e9+7;

        for(int i=1; i<pat.length(); i++){
            patHash = (patHash + (pat[i]-'a'+1)*power)%mod;
            power = (power*p)%mod;
        }

        // rabin karp algo starts
        power = p;
        vector<long> dp(txt.length());
        vector<long> pi(txt.length());

        dp[0] = txt[0]-'a'+1;
        pi[0] = 1;

        for(int i=1; i<txt.length(); i++){
            dp[i] = (dp[i-1] + (txt[i]-'a'+1)*power)%mod;
            pi[i] = power;
            power = (power*p)%mod;
        }

        vector<int> ans;
        int sp=0;
        int ep=pat.length()-1;

        while(ep<txt.length()){
            long curWindowHashValue = dp[ep];

            if(sp>0){
                curWindowHashValue = (curWindowHashValue - dp[sp-1] + mod) % mod;
            }

            if(curWindowHashValue == (patHash*pi[sp])%mod){
                ans.push_back(sp+1);
            }
            sp++;
            ep++;
        }

        if(ans.size()==0){
            vector<int> v(1);
            v[0] = -1;
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