// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n=arr.size();
	    vector<int> dp1(n, 0);
	    dp1[0] = 1;
	    
	    for(int i=1; i<n; i++){
	        int maxi = 0;
	        for(int j=0; j<i; j++){
	           if(arr[j] < arr[i]){
	               maxi = max(maxi, dp1[j]);
	           }
	        }
	        
	        dp1[i] = maxi + 1;
	    }
	    
	    vector<int> dp2(n, 0);
	    dp2[n-1] = 1;
	    
	    for(int i=n-2; i>=0; i--){
	        int maxi=0;
	        for(int j=n-1; j>i; j--){
	            if(arr[j] < arr[i]){
	                maxi = max(maxi, dp2[j]);
	            }
	        }
	        
	        dp2[i] = maxi + 1;
	    }
	    
	    int maxi=0;
	    for(int i=0; i<n; i++){
	        maxi = max(maxi, dp1[i] + dp2[i] - 1);
	    }
	    
	    return maxi;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends