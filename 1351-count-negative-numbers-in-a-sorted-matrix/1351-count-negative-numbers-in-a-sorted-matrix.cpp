class Solution {
public:
    int findFirstNegativeIndexInEachRow(vector<int>& arr){
        
        int n = arr.size();
        
        int low=0;
        int high=n-1;
        
        int index = n;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(arr[mid] < 0){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return index;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        
        int totalNegativeNumbers = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            
            int index = findFirstNegativeIndexInEachRow(grid[i]);
            
            totalNegativeNumbers += (n - index);
        }
        
        return totalNegativeNumbers;
    }
};