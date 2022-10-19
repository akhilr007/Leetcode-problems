class Compare{
public:
    bool operator()(const pair<string, int>&a, const pair<string, int>&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> m;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        
        for(auto it : m){
            pq.push({it.first, it.second});
            if(pq.size()>k) pq.pop();
        }
        
        vector<string> res(pq.size());
        for(int i=pq.size()-1; i>=0; i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};