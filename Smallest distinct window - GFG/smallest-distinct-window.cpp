// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char> s;
        for(int i=0; i<str.length(); i++){
            s.insert(str[i]);
        }
        
        int size=s.size();
        
        int ans=INT_MAX;
        int i=0;
        int j=0;
        
        unordered_map<char, int> m;
        
        while(j<str.length()){
            
            m[str[j]]++;
            
            if(m.size() < size){
                j++;
            }
            
            else if(m.size() == size){
                
                ans = min(ans, j-i+1);
                
                while(m.size() == size){
                    
                    m[str[i]]--;
                    if(m[str[i]] == 0){
                        m.erase(str[i]);
                    }
                    
                    ans = min(ans, j-i+1);
                    i++;
                }
                
                j++;
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends