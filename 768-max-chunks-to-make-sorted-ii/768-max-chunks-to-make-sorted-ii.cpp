class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> lmax(n);
        lmax[0] = arr[0];
        
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1], arr[i]);
        }
        
        vector<int> rmin(n+1);
        rmin[n] = INT_MAX;
        
        for(int i=n-1; i>=0; i--){
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        
        int countChunks=0;
        for(int i=0; i<n; i++){
            if(lmax[i] <= rmin[i+1]){
                countChunks++;
            }
        }
        
        return countChunks;
        
    }
};