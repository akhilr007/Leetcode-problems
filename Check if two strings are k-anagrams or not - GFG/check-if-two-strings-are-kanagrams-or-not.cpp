// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        
        unordered_map<char, int> s;
        
        if(str1.length() != str2.length()){
            return false;
        }
        
        for(int i=0; i<str1.length(); i++){
            s[str1[i]]++;;
        }
        
        int count=0;
        for(int i=0; i<str2.length(); i++){
            
            char ch = str2[i];
            
            if(s.find(ch) != s.end()){
                s[ch]--;
                if(s[ch] == 0){
                    s.erase(ch);
                }
            }
            else{
                count++;
                if(count>k){
                return false;
                }
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends