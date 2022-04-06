// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        
        ll count=0;
        ll sum=0;
        
        for(int i=0; i<arr.size(); i++){
            
            sum += arr[i];
            
            if(mp.find(sum) == mp.end()){
                mp[sum]++;
            }
            else{
                count += mp[sum];
                mp[sum]++;
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
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends