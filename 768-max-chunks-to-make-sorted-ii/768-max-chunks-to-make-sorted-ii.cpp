class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> rmin(n+1);
        rmin[n] = INT_MAX;
        
        for(int i=n-1; i>=0; i--){
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        
        int countChunks=0;
        int lmax = INT_MIN;
        for(int i=0; i<n; i++){
            lmax = max(lmax, arr[i]);
            if(lmax <= rmin[i+1]){
                countChunks++;
            }
        }
        
        return countChunks;
        
    }
};