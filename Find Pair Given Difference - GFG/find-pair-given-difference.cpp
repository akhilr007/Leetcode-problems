// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    
    sort(arr, arr+size);
    // 2 3 5 5 20 80
    
    // 1 2 3 4 6 target = 0
    
    int i=0;
    int j=1;
    
    while(i<size-1 && j<size){
        
        if(i!=j){
            if(arr[j]-arr[i]==n) return true;
            
            else if(arr[j]-arr[i] < n) j++;
            
            else if(arr[j]-arr[i] > n) i++;
        }
        else {
            j++;
        }
        
    }
    
    return false;
    
}