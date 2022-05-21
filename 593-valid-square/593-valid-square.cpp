class Solution {
public:
    bool findDistance(vector<int>& a, vector<int>& b, unordered_set<int>& s){
        
        if(a[0]==b[0] && a[1] == b[1]) return false;
        
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        
        int dist = dx*dx + dy*dy;
        s.insert(dist);
        
        if(s.size()>2) return false;
        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<int> s;
        
        if(!findDistance(p1, p2, s) || !findDistance(p1, p3, s) || !findDistance(p1, p4, s) || !findDistance(p2, p3, s) || !findDistance(p2, p4, s) || !findDistance(p3, p4, s)){
            return false;
        }
        
        // square will have two sides one for outer side and one diagonal
        
        return s.size()==2 ? true : false;
    }
};