class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int> pq;
        // nlogn
        int sum=0;
        for(int i=0; i<n; i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }
        
        // klogn
        while(k-->0){
            int max_val = pq.top(); // 9
            pq.pop();
            
            int removeVal = max_val/2; // 4
            sum -= removeVal;
            
            max_val -= removeVal;
            pq.push(max_val);
        }
        
        return sum;
        
    }
};