class compare{
public:
    bool operator()(pair<int, int>&a, pair<int ,int>& b){
        
        if(a.second==b.second) return a.first<b.first;
        else return a.second < b.second;
    }
};

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // we can have a priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // first -> val , second -> diff with value
        
        for(int i=0; i<arr.size(); i++){
            
            int gap = abs(arr[i]-x);
            
            if(pq.size()<k){
                pq.push({arr[i], gap});
            }
            else{
                if(pq.top().second > gap){
                    pq.pop();
                    pq.push({arr[i], gap});
                }
            }
            
        }
        
        vector<int> res;
        
        while(pq.size()>0) {
            int val = pq.top().first;
            pq.pop();
            res.push_back(val);
        }
        
        sort(res.begin(), res.end());
        return res;
        
        
    }
};