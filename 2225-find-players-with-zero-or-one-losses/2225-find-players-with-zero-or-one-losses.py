class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        
        winnerMapping, loserMapping = {}, {}
        
        for match in matches:
            winnerMapping[match[0]] = winnerMapping.get(match[0], 0)+1
            loserMapping[match[1]] = loserMapping.get(match[1], 0)+1
        
        winners, losers = [], []
        for player in winnerMapping.keys():
            winsCount = winnerMapping.get(player)
            if player not in loserMapping:
                winners.append(player)
        
        for player in loserMapping.keys():
            lostCount = loserMapping.get(player)
            if lostCount == 1:
                losers.append(player)
        
        winners.sort()
        losers.sort()
        result=[]
        result.append(winners)
        result.append(losers)
        return result
    