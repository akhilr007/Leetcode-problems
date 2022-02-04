class Solution {
public:
    int maxArea(vector<int>& height) {
        
    int n = height.size();
    
    int maximumArea = INT_MIN;

    int i=0;
    int j=n-1;

    while(i<j){

        int width = (j-i);
        int heights = min(height[i], height[j]);

        int currArea = width*heights;

        maximumArea = max(maximumArea, currArea);

        if(height[i] < height[j]){
            i++;
        } 
        else{
            j--;
        }
    }

    return maximumArea;
    }
};