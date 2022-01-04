class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        
        int max_area=0;
        
        while(i<j){
            
            int width = (j-i);
            
            int min_height;
            int curr_area;
            
            if(height[i] < height[j]){
                
                min_height = height[i]; 
                curr_area = width * min_height;
                i++;
            }
            else{
                min_height = height[j];
                curr_area = width * min_height;
                j--;
            }
            
            max_area = max(curr_area, max_area);
            
        }
        
        return max_area;
        
    }
};