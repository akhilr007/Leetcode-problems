class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        output = []
        
        for i in range(len(intervals)):
            
            if newInterval[1] < intervals[i][0]:
                output.append(newInterval)
                output = output + intervals[i:]
                return output
            
            elif newInterval[0] > intervals[i][1]:
                output.append(intervals[i])
            
            else:
                newInterval[0] = min(newInterval[0], intervals[i][0])
                newInterval[1] = max(newInterval[1], intervals[i][1])
        
        output.append(newInterval)
        return output
    