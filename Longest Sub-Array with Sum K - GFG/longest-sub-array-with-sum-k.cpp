//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxlen=0;
        
        map<long long, int> preSumMap;
        long long sum = 0;
        
        for(int i=0; i<N; i++){
            
            
            sum += A[i];
            
            if(sum == K){
                maxlen = max(maxlen, i+1);
            }
            
            int rem = sum - K;
            if(preSumMap.find(rem) != preSumMap.end()){
                maxlen = max(maxlen, i - preSumMap[rem]);
            }
            
            // works in 
            if(preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }
        
        
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends