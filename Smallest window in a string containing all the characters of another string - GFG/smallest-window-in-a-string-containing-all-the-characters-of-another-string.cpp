// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int count=0;
        int m[256] = {0};
        
        for(int i=0; i<p.length(); i++){
            if(m[p[i]] == 0) count++;
            m[p[i]]++;
        }
        
        int res=INT_MAX;
        int start=0;
        int i=0, j=0;
        
        while(j<s.length()){
            
            m[s[j]]--;
            
            if(m[s[j]] == 0) count--;
            
            if(count == 0){
                
                while(count == 0){
                    
                    if(res > j-i+1){
                        res = j-i+1;
                        start = i;
                    }
                    
                    m[s[i]]++;
                    if(m[s[i]] == 1) count++;
                    i++;
                }
            }
            j++;
        }
        
        if(res == INT_MAX) return "-1";
        return s.substr(start, res);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends