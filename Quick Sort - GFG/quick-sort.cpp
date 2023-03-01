//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            
            int pIndex = partition(arr, low, high);
            
            quickSort(arr, low, pIndex - 1);
            quickSort(arr, pIndex+1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[low];
       
       int l=low;
       int r=high;
       
       while(l < r){
           
           while(arr[l] <= pivot && (l <= high)){
               l++;
           }
           
           while(arr[r] > pivot && (r >= low)){
               r--;
           }
           
           if(l < r) swap(arr[l], arr[r]);
       }
       
       swap(arr[low], arr[r]);
       return r;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends