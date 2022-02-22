#define ll long long
class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<ll> pq;
        ll total_sum=0;
        
        for(auto it: target){
            pq.push(it);
            total_sum += it;   
        }
        
        while(pq.size()>0){
            
            ll top = pq.top(); pq.pop();
            ll remaining_sum = total_sum - top;
            
            if(top==1 || remaining_sum ==1) return true;
            
            if(remaining_sum==0 || top < remaining_sum) return false;
            
            int val = (int)(top%remaining_sum);
            
            if(val==0) return false;
            
            pq.push(val);
            total_sum = remaining_sum + val;
        }
        
        return true;
    }
};