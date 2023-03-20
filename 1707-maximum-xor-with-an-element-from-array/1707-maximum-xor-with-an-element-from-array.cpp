struct Node {
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    
    void insert(int bit, Node* node){
        links[bit] = node;
    }
    
    Node* getNode(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        
        Node* node = root;
        
        for(int i=31; i>=0; i--){
            
            int bit = (num>>i) & 1;
            
            if(!node->containsKey(bit)){
                node->insert(bit, new Node());
            }
            
            node = node->getNode(bit);
        }
    }
    
    int getMax(int num){
        
        Node* node = root;
        int maxNum = 0;
        
        for(int i=31; i>=0; i--){
            
            int bit = (num>>i) & 1;
            
            if(node->containsKey(1-bit)){
                
                maxNum = maxNum | (1<<i);
                node = node->getNode(1-bit);
            }
            else{
                node = node->getNode(bit);
            }
        }
        
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        vector<pair<int, pair<int, int>>> oq;
        int q = queries.size();
        
        for(int i=0; i<q; i++){
            oq.push_back({ queries[i][1], {queries[i][0], i}});
        }
        
        sort(begin(oq), end(oq));
        
        vector<int> ans(q, 0);
        int ind = 0;
        
        Trie trie;
        
        for(int i=0; i<q; i++){
            
            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int qInd = oq[i].second.second;
            
            while(ind < n && nums[ind] <= ai){
                
                trie.insert(nums[ind]);
                ind++;
            }
            
            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.getMax(xi);
        }
        
        return ans;
    }
};