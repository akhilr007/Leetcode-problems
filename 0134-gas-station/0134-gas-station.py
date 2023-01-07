class Solution:
    def bruteForce(self, gas: List[int], cost: List[int]) -> int:
        
        N = len(gas)
        
        for i in range(N):
            if gas[i] < cost[i]:
                continue
            
            curGas = gas[i]
            j = (i + 1) % N
            
            costForNextMove = cost[i]
            gasEarnFromNextStation = gas[j]
            
            curGas = curGas - costForNextMove + gasEarnFromNextStation
            
            while i!=j:
                if curGas < cost[j]:
                    break
                
                costForNextMove = cost[j]
                
                j = (j + 1)%N
                
                gasEarnFromNextStation = gas[j]
                
                curGas = curGas - costForNextMove + gasEarnFromNextStation
            
            if i==j:
                return i
        
        return -1
           
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        totalGasNeeded = sum(gas)
        totalCostNeeded = sum(cost)
        
        if totalGasNeeded < totalCostNeeded:
            return -1
        
        N = len(gas)
        result_idx = 0 # probable answer
        totalCost = 0
        
        for i in range(N):
            totalCost += gas[i] - cost[i]
            
            if totalCost < 0:
                totalCost = 0
                result_idx = i+1
        
        return result_idx
    
        
    