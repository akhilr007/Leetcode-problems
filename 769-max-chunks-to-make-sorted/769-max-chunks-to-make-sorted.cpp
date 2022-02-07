class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int maxImpact = INT_MIN;
        int countChunks=0;
        
        for(int i=0; i<arr.size(); i++){
            // max impact of current element
            maxImpact = max(maxImpact, arr[i]);
            
            // if the idx is equal to maxImpact idx then we can make partition
            if(maxImpact == i){
                countChunks++;
            }
        }
        
        return countChunks;
        
    }
};