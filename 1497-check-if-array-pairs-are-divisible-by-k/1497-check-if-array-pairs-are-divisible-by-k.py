class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        
        if len(arr)%2 == 1:
            return False
        
        fmap = {}
        for ele in arr:
            rem = ((ele%k) + k) % k;
            fmap[rem] = fmap.get(rem, 0) + 1
        
        
        for ele in arr:
            rem = ((ele%k) + k) % k;
            
            if rem == 0:
                if fmap[rem] % 2 == 1:
                    return False
            else:
                if fmap[rem] != fmap.get(k-rem, 0):
                    return False
        
        return True
    