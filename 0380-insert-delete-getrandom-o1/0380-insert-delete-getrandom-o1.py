class RandomizedSet:
    def __init__(self):
        self.nums = []
        self.indexMap = {}
    
    def insert(self, val: int) -> bool:
        if val in self.indexMap:
            return False
        
        self.nums.append(val)
        self.indexMap[val] = len(self.nums)-1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.indexMap:
            return False
        
        idx = self.indexMap.get(val)
        lastElement = self.nums[-1]
        self.nums[-1] = val
        
        self.nums[idx] = lastElement
        self.indexMap[lastElement] = idx
        
        self.nums.pop()
        del self.indexMap[val]
        return True

    def getRandom(self) -> int:
        randomIndex = random.randint(0, len(self.nums)-1)
        return self.nums[randomIndex]
