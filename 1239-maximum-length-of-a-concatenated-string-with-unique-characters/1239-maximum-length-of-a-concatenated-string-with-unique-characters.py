class Solution:
    def maxLength(self, arr: List[str]) -> int:
        
        hashset = set()
        def isOverlap(curString):
            selfCheck = set()
            for s in curString:
                if s in selfCheck:
                    return True
                selfCheck.add(s)
            
            
            for s in curString:
                if s in hashset:
                    return True
            
            return False
        
        def helper(idx, length):
            if idx >= len(arr):
                return length
            
            curString = arr[idx]
            if isOverlap(curString):
                return helper(idx+1, length)
            else:
                # pick the string
                for s in curString:
                    hashset.add(s)
                
                length += len(curString)
                op1 = helper(idx+1, length)
                
                # skip the string
                for s in curString:
                    hashset.remove(s)
                
                length -= len(curString)
                op2 = helper(idx+1, length)
                
                return max(op1, op2)
            
        return helper(0, 0)
        