class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        
        queue<int> rQ, dQ;
        
        for(int i=0; i<n; i++){
            if(senate[i] == 'R')
                rQ.push(i);
            else
                dQ.push(i);
        }
        
        while(!rQ.empty() && !dQ.empty()){
            
            int rs = rQ.front();
            rQ.pop();
            
            int ds = dQ.front();
            dQ.pop();
            
            if(rs < ds){
                rQ.push(rs + n);
            }
            else{
                dQ.push(ds + n);
            }
        }
        
        return rQ.empty() == false ? "Radiant" : "Dire";
    }
};