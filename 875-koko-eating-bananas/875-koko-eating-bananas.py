import sys
class Solution:
    def canEat(self, piles: List[int], h: int, mid: int) -> bool:
        
        no_of_hours=0
        
        for pile in piles:
            hours = pile//mid
            no_of_hours += hours
            
            if pile%mid != 0:
                no_of_hours += 1
        
        return no_of_hours <= h
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        start = 1
        end = max(piles)
        
        ans = end
        
        while start <= end:
            mid = (start + end)//2
            
            if self.canEat(piles, h, mid) == True:
                ans = min(ans, mid)
                end = mid - 1
            
            else:
                start = mid + 1
        return ans