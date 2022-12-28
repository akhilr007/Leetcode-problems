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
            sum -= max_val;
            
            int reduceVal = ceil(max_val/2.0); // 4
            sum += reduceVal;
            
            pq.push(reduceVal);
        }
        
        return sum;
        
    }
};