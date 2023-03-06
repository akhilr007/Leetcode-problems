class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int l=0;
        int r=n-1;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            int numberOfMissingNumbersTillMid = arr[mid] - (mid + 1);
            
            if(numberOfMissingNumbersTillMid < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l + k;
    }
};