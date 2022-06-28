class Solution:
    def minDeletions(self, s: str) -> int:
        
        count = [0]*26
        
        for c in s:
            count[ord(c) - ord("a")] += 1
            
        
        count.sort(reverse=True)
        flag = count[0]
        ans = 0
        
        for val in count:
            if val > flag:
                if flag>0:
                    ans += val - flag
                else:
                    ans += val
            flag = min(flag-1, val-1)
            
        return ans