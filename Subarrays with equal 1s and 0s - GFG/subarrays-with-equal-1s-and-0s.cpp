// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        long long int count=0;
        int sum=0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i] == 0){
                sum += -1;
            }
            else if(arr[i] == 1){
                sum += 1;
            }
            
            if(mp.find(0) == mp.end()){
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends