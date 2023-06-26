class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();
        
        priority_queue<int, vector<int>, greater<int> > head;
        priority_queue<int, vector<int>, greater<int> > tail;
        
        for(int i=0; i<candidates; i++){
            head.push(costs[i]);
        }
        
        for(int i=max(candidates, n-candidates); i<n; i++){
            tail.push(costs[i]);
        }
        
        long long result = 0;
        
        int nextHead = candidates;
        int nextTail = n-candidates-1;
        
        for(int i=0; i<k; i++){
            
            if(tail.size()==0 || (head.size()>0 && head.top() <= tail.top())){
                result += head.top();
                head.pop();
                
                if(nextHead <= nextTail){
                    head.push(costs[nextHead]);
                    nextHead++;
                }
            }
            else{
                result += tail.top();
                tail.pop();
                
                if(nextHead <= nextTail){
                    tail.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return result;
    }
};