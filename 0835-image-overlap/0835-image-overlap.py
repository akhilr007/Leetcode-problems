class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        
        p1, p2 = [], []
        length = len(A)
        
        for i in range(length):
            for j in range(length):
                
                if A[i][j] == 1:
                    p1.append([i, j])
                
                if B[i][j] == 1:
                    p2.append([i, j])
        
        count = {}
        maxOverlap=0
        
        for a in p1:
            for b in p2:
                x = a[0] - b[0]
                y = a[1] - b[1]
                
                s = str(x)+"#"+str(y)
                count[s] = count.get(s,0) + 1;
                
                maxOverlap = max(maxOverlap, count[s])
                
        return maxOverlap
    