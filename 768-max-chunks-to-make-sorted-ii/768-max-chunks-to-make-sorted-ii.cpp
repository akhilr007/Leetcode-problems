class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> left_max(n);
        left_max[0] = arr[0];
        
        for(int i=1; i<n; i++){
            left_max[i] = max(arr[i], left_max[i-1]);
        }
        
        vector<int> right_min(n+1);
        right_min[n] = INT_MAX;
        
        for(int i=n-1; i>=0; i--){
            
            right_min[i] = min(arr[i], right_min[i+1]);
            
        }
        
        int chunks=0;
        for(int i=0; i<n; i++){
            
            if(left_max[i] <= right_min[i+1]){
                chunks++;
            }
        }
        
        return chunks;
    }
};