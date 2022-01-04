class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        
        int max_area=0;
        
        while(i<j){
            
            int width = (j-i);
            
            int min_height_for_calculating_area = min(height[i], height[j]);
            
            int curr_area = width * min_height_for_calculating_area;
            
            
            max_area = max(curr_area, max_area);
            
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return max_area;
        
    }
};