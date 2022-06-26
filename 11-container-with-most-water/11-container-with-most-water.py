class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        l, r = 0, len(height)-1
        res=0
        
        while l<r:
            
            width = r-l
            h = 0
            if height[l] < height[r]:
                h = height[l]
                l += 1
            else:
                h = height[r]
                r -= 1
            
            currArea = h * width
            res = max(currArea, res)
            
        return res
            