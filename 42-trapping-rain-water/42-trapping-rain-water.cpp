class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        if(n==0) return 0;
        
        int leftMax = height[0];
        int rightMax = height[n-1];
        
        int l=0, r=n-1, res=0;
        
        while(l<r){
            
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else{
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        
        return res;
    }
};