class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        vector<int> height = {horizontalCuts[0]};
        for(int i=1; i<horizontalCuts.size(); i++){
            height.push_back(horizontalCuts[i] -horizontalCuts[i-1]);
        }
        
        height.push_back(h - horizontalCuts[horizontalCuts.size()-1]);
        
        vector<int> width = {verticalCuts[0]};
        for(int i=1; i<verticalCuts.size(); i++){
            width.push_back(verticalCuts[i] - verticalCuts[i-1]);
        }
        
        width.push_back(w -verticalCuts[verticalCuts.size()-1]);
        
        long maxHeight=0, maxWidth = 0;
        
        maxHeight = *max_element(height.begin(), height.end());
        maxWidth = *max_element(width.begin(), width.end());
        
        long mod = 1e9+7;
        long ans = (maxHeight * maxWidth);
        ans %= mod;
        return (int)ans;
    }
};