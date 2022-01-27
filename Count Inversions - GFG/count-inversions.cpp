// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ic=0;
    
    vector<long long> merge(vector<long long>& left, vector<long long>& right){
        
        int n = left.size();
        int m = right.size();
        
        vector<long long> res(n+m, 0);
        
        int i=0;
        int j=0;
        int k=0;
        
        while(i<n && j<m){
            if(left[i] <= right[j]){
                res[k] = left[i];
                i++;
                k++;
            }
            else{
                ic += n-i;
                res[k] = right[j];
                j++;
                k++;
            }
        }
        
        while(i<n){
            res[k] = left[i];
            i++;
            k++;
        }
        
        while(j<m){
            res[k] = right[j];
            j++;
            k++;
        }
        
        return res;
    }
    
    vector<long long> mergeSort(long long arr[], int lo, int hi){
        
        if(lo == hi){
            vector<long long> ba(1);
            ba[0] = arr[lo];
            return ba;
        }
        
        int mid = lo + (hi-lo)/2;
        
        vector<long long> left = mergeSort(arr, lo, mid);
        vector<long long> right = mergeSort(arr, mid+1, hi);
        
        vector<long long> ans = merge(left, right);
        
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        ic=0;
        mergeSort(arr, 0, (int)N-1);
        return ic;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends