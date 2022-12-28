class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int> pq;
        // nlogn
        for(int i=0; i<n; i++) pq.push(piles[i]);
        
        // klogn
        while(k-->0){
            int val = pq.top();
            pq.pop();
            
            int tempVal = ceil(val/2.0);
            pq.push(tempVal);
        }
        
        int sum=0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
        
    }
};