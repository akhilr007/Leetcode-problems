class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        
        TreeMap<Integer, Integer> winnerMapping = new TreeMap<>();
        TreeMap<Integer, Integer> loserMapping = new TreeMap<>();
        
        for(int[] match: matches){
            winnerMapping.put(match[0], winnerMapping.getOrDefault(match[0],0)+1);
            loserMapping.put(match[1], loserMapping.getOrDefault(match[1],0)+1);
        }
        
        List<Integer> winners = new ArrayList<>();
        List<Integer> losers = new ArrayList<>();
        
        for(int player: winnerMapping.keySet()){
            int winsCount = winnerMapping.get(player);
            
            if(loserMapping.containsKey(player) == false){
                winners.add(player);
            }
        }
        
        for(int player: loserMapping.keySet()){
            int lostCount = loserMapping.get(player);
            if(lostCount == 1){
                losers.add(player);
            }
        }
        
        List<List<Integer>> result = new ArrayList<>();
        result.add(winners);
        result.add(losers);
        return result;
    }
}