// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        
        // int ans=0;
        // for(int i=0; i<=n-k; i++){
        //     int sum=0;
        //     for(int j=i; j<i+k; j++){
                
        //         sum += arr[j];
        
        //     }
        //     ans = max(ans, sum);
        // }
        
        // return ans;
        
        int i=0, j=0;
        
        int ans =0;
        int sum=0;
        
        while(j<n){
            
            sum += arr[j];
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
                ans = max(ans, sum);
                
                sum -= arr[i];
                i++;
                j++;
                
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends