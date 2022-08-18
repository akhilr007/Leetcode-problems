class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> count;
        for(auto x : arr){
            count[x]++;
        }
        
        priority_queue<int> pq;
        for(auto it : count){
            pq.push(it.second);
        }
        
        int n = arr.size();
        int minSets=0;
        int elementsRemoved = 0;
        
        while(elementsRemoved < n/2){
            
            elementsRemoved += pq.top();
            minSets += 1;
            pq.pop();
        }
        
        return minSets;
        
    }
};