class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n=hand.size();
        
        if(n%groupSize == 1) return false;
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++){
            
            if(m.find(hand[i]) == m.end()){
                m[hand[i]] = 1;
                pq.push(hand[i]);
            }
            else{
                m[hand[i]]++;
            }
        }
        
        while(pq.size()>0){
            
            int val = pq.top();
            
            for(int i=val; i<val+groupSize; i++){
                if(m.find(i) == m.end()) return false;
                
                m[i]--;
                
                if(m[i] == 0){
                    if(i != pq.top()) return false;
                    m.erase(m[i]);
                    pq.pop();
                }
            }
        }
        
        return true;
    }
};