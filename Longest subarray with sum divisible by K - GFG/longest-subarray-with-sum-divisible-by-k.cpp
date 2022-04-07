// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int, int> mp;
	    mp[0] = -1;
	    
	    int sum=0;
	    int maxlen=0;
	    
	    for(int i=0; i<n; i++){
	        
	        sum += arr[i];
	        
	        if(mp.find((sum%k + k)%k) == mp.end()){
	            mp[(sum%k + k)%k] = i;
	        }
	        else{
	            maxlen = max(maxlen, i-mp[(sum%k + k)%k]);
	        }
	    }
	    
	    return maxlen;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends