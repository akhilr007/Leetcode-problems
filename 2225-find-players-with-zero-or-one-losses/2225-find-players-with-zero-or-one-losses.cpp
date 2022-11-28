class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int> winnersMapping;
        map<int, int> losersMapping;
        
        for(auto match: matches){
            winnersMapping[match[0]]++;
            losersMapping[match[1]]++;
        }
        
        vector<int> winners;
        vector<int> losers;
        
        for(auto it: winnersMapping){
            int player = it.first;
            int winsCount = it.second;
            
            if(losersMapping.find(player) == losersMapping.end()){
                winners.push_back(player);
            }
        }
        
        for(auto it: losersMapping){
            int player = it.first;
            int lostCount = it.second;
            
            if(lostCount == 1){
                losers.push_back(player);
            }
        }
        
        vector<vector<int>> result;
        result.push_back(winners);
        result.push_back(losers);
        
        return result;
    }
};