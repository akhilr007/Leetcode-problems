class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        if(start == end) return 0;
        
        unordered_set<string> allowed;
        unordered_set<string> visit;
        unordered_set<char> chars;
        
        chars.insert('A');
        chars.insert('C');
        chars.insert('G');
        chars.insert('T');
        
        for(auto s : bank) allowed.insert(s);
        
        queue<string> q;
        q.push(start);
        visit.insert(start);
        
        int level=0;
        
        while(q.size()>0){
            
            int size=q.size();
            while(size-- > 0){
                
                auto str = q.front();
                q.pop();
                
                for(int i=0; i<str.size(); i++){
                    
                    for(auto x: chars){
                        
                        string change = str;
                        change[i] = x;
                        
                        if(visit.find(change) == visit.end() && allowed.find(change) != allowed.end()){
                            if(change == end) return level+1;
                            
                            q.push(change);
                            visit.insert(change);
                            
                        }
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};