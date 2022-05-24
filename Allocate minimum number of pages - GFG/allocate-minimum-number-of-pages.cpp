// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool allocationPossible(int arr[], int barrier, int m, int n){
        
        int allocatedStudent=1;
        int pages=0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i] > barrier) return false;
            
            if(pages + arr[i] > barrier){
                allocatedStudent += 1;
                pages=arr[i];
            }
            else{
                pages += arr[i];
            }
        }
        
        if(allocatedStudent > m) return false;
        else return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        int low=1e8;
        int high=0;
        int result=-1;
        
        for(int i=0; i<N; i++){
            low = min(low, arr[i]);
            high += arr[i];
        }
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            if(allocationPossible(arr, mid, M, N)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends