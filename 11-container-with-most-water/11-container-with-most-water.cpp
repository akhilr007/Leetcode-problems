class Solution {
public:
    int maxArea(vector<int>& arr) {
        
//         int maxArea=0;
//         for(int i=0; i<height.size(); i++){
//             for(int j=i+1; j<height.size(); j++){
                
//                 int currArea = (j-i)*min(height[i], height[j]);
                
//                 if(currArea > maxArea){
//                     maxArea = currArea;
//                 }
                
//             }
//         }
        
//         return maxArea;
        
        int i=0;
        int j=arr.size()-1;
        
        int maxArea=0;
        
        while(i<j){
            
            // compare b/w heights of i and j
            int minHeight = min(arr[i], arr[j]);
            int currArea = (j-i)*minHeight;
            
            if(currArea > maxArea){
                maxArea = currArea;
            }
            
            // if height of arr[i] is smaller , then increment i otherwise decrement j'
            if(arr[i]<arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return maxArea;
    }
};