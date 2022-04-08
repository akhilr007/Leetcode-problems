// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        
        unordered_map<string, int> mp;
        
        int countOne=0;
        int countZero=0;
        int countTwo=0;
        
        int delta01 = countOne - countZero;
        int delta21 = countTwo - countOne;
        
        string key = to_string(delta01) + "#" + to_string(delta21);
        
        mp[key] = 1; 
        
        long long count=0;
        
        for(int i=0; i<str.length(); i++){
            
            if(str[i] == '0'){
                countZero++;
            }
            else if(str[i] == '1'){
                countOne++;
            }
            else if(str[i] == '2'){
                countTwo++;
            }
            
            delta01 = countOne - countZero;
            delta21 = countTwo - countOne;
            
            key = to_string(delta01) + "#" + to_string(delta21);
            
            if(mp.find(key) != mp.end()){
                count += mp[key];
                mp[key]++;
            }
            else{
                mp[key]++;
            }
            
        }
        
        return count;
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
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends