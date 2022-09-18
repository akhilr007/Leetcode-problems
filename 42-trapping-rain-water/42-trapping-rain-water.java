class Solution {
    public int trap(int[] height) {
        
        int n = height.length;
        
        int leftMax = height[0];
        int rightMax = height[n-1];
        
        int l=0;
        int r=height.length-1;
        int ans=0;
        
        while(l<r){
            if(leftMax < rightMax){
                l++;
                leftMax = Math.max(leftMax, height[l]);
                ans += leftMax - height[l];
            }
            else{
                r--;
                rightMax = Math.max(rightMax, height[r]);
                ans += rightMax - height[r];
            }
        }
        
        return ans;
    }
}