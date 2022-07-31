class Solution:
    def minJumps(self, arr: List[int]) -> int:
        
        maps = {}
        for i in range(len(arr)):
            if arr[i] in maps:  
                new = maps[arr[i]]
                new.append(i)
                maps[arr[i]] = new
            else:
                maps[arr[i]] = [i]
        
        visit = set()
        q = deque()
        q.append(0)
        
        level = 0
        while q:
            size = len(q)
            for i in range(size):
                
                head = q.popleft()
                
                if head == len(arr)-1:
                    return level
                
                if head < 0 or head >= len(arr) or head in visit:
                    continue
                
                if head-1 > 0 and head-1 not in visit:
                    q.append(head - 1)
                
                if head+1 < len(arr) and head+1 not in visit:
                    q.append(head + 1)
                    
                if arr[head] in maps:
                    indexes = maps[arr[head]]
                    for idx in indexes:
                        if idx > 0 and idx < len(arr) and idx not in visit:
                            q.append(idx)
                    
                    del maps[arr[head]]
                
                visit.add(head)
                
            level += 1
        
        return -1
    
        