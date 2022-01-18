class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int count=0;
        int maxR =0;
        
        for(int i=0; i<arr.size(); i++){
            
            maxR = max(arr[i], maxR);
            
            if(i == maxR){
                count++;
            }
        }
        
        return count;
    }
};