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
            int val = pq.top();
            pq.pop();
            sum -= val;
            
            int tempVal = ceil(val/2.0);
            sum += tempVal;
            pq.push(tempVal);
        }
        
        return sum;
        
    }
};