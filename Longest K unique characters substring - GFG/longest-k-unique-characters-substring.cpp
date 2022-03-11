// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        
        int len=0;
        for(int i=0; i<s.length(); i++){
            int count=0;
            vector<int> v(27, 0);
            for(int j=i; j<s.length(); j++){
                if(v[s[j] - 'a'] == 0){
                    v[s[j]-'a'] = 1;
                    count++;
                }
                
                if(count > k) break;
                
                if(count == k){
                    len = max(len, j-i+1);
                }
            }
            
        }
        return len == 0 ? -1 : len;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends