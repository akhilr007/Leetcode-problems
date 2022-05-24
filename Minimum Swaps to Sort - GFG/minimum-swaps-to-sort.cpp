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
	    int n=nums.size();
	    vector<pair<int, int>> sortedArr(n);
	    for(int i=0; i<n; i++){
	        sortedArr[i] = {nums[i], i};
	    }
	    sort(sortedArr.begin(), sortedArr.end());
	    
	    int count=0;
	    for(int i=0; i<n; i++){
	        if(sortedArr[i].second == i) continue;
	        
	        else{
	            count++;
	            swap(sortedArr[sortedArr[i].second], sortedArr[i]);
	            i--;
	        }
	    }
	    
	    return count;
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