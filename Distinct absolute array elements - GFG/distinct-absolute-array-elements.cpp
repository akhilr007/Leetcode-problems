// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int distinctCount(int arr[], int n) {
        
       int i=0;
       int j=n-1;
       
       int prev = INT_MIN;
       int next = INT_MAX;
       
       int count=0;
       while(i<=j){
           
           if(abs(arr[i]) == abs(arr[j])){
               
               if(arr[i] != prev && arr[j] != next){
                   count++;
               }
               
               prev = arr[i];
               next = arr[j];
               i++;
               j--;
           }
           
           else if(abs(arr[i]) > abs(arr[j])){
               
               if(arr[i] != prev){
                   count++;
               }
               prev = arr[i];
               i++;
           }
           
           else{
               if(arr[j] != next){
                   count++;
               }
               next = arr[j];
               j--;
           }
       }
       
       return count;
       
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.distinctCount(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends