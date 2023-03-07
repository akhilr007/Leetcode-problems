class Solution:
    def tripsTaken(self, time, unit):
        cnt = 0
        for x in time:
            cnt += unit // x
        return cnt
    
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        
        low, high = 1, int(1e14)
        ans = high
        
        while low <= high:
            mid = (low + high) // 2
            
            if self.tripsTaken(time, mid) >= totalTrips:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans
    