// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int, int>> arr(n);
	    
	    for(int i=0; i<n; i++){
	        arr[i] = make_pair(nums[i], i);
	    }
	    
	    sort(arr.begin(), arr.end());
	    
	    vector<bool> vis(n, false);
	    
	    int ans=0;
	    for(int i=0; i<n; i++){
	        if(vis[i] == true or arr[i].second == i){
	            continue;
	        }
	        
	        int clen=0;
	        int j=i;
	        while(vis[j] == false){
	            vis[j] = true;
	            clen++;
	            j = arr[j].second;
	        }
	        
	        ans += clen-1;
	    }
	    
	    return ans;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends