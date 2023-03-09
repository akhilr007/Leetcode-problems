//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int nums[], int k, int n) 
	{ 
	   // Your code goes her
        k = k % n;
        
        int temp[k];
        for(int i=0; i<k; i++){
            temp[i] = nums[i];
        }

        for(int i=k; i<n; i++){
            nums[i-k] = nums[i];
        }

        for(int i=n-k; i<n; i++){
            nums[i] = temp[i-(n-k)];
        }
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends