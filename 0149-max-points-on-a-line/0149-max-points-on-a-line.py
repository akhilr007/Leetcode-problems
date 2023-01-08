class Solution:
    def findGCD(self, a, b):
        if b == 0:
            return a
        
        return self.findGCD(b, a%b)
    
    def maxPoints(self, points: List[List[int]]) -> int:
        
        N = len(points)
        
        if N == 1:
            return 1
        
        result = 0
        
        for i in range(N):
            
            freq = {}
            
            for j in range(N):
                
                if i == j:
                    continue
                
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                
                gcd = self.findGCD(max(dx, dy), min(dx, dy))
                
                key = str(dx // gcd) + "_" + str(dy // gcd)
                
                freq[key] = freq.get(key, 0) + 1
            
            for key in freq.keys():
                result = max(result, freq[key]+1)
        
        return result
    