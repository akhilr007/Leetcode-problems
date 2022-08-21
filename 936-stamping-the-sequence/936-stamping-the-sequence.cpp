class Solution {
public:
    
    void update(string& curr, int i, string& stamp){
        
        for(int j=0; j<stamp.length(); j++){
            curr[j+i] = '*';
        }
    }
    
    int fetchStampIndex(string& curr, string& stamp){
        
        
        for(int i=0; i<=curr.length() - stamp.length();i++){
            
            int j=0; // for stamp 
            int s = i; // for curr
            bool isNotStarChar = false;
            
            while(j<stamp.length() && s<curr.length() && (curr[s] == '*' || curr[s] == stamp[j])){
                if(curr[s] != '*') isNotStarChar = true;
                s++;
                j++;
            }
            
            if(j==stamp.length() && isNotStarChar){
                return i;
            }
        }
        
        return -1;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> res;
        
        string curr = target;
        string targetStr(target.length(), '*');
        
        
        while(curr != targetStr){
            
            int stampIndex = fetchStampIndex(curr, stamp);
            if(stampIndex < 0){
                vector<int> v;
                return v;
            }
            else{
                update(curr, stampIndex, stamp);
            }
            
            res.push_back(stampIndex);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};