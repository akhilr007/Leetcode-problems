class Solution {
public:
    
    void update(string& curr, int i, string& stamp){
        
        for(int j=0; j<stamp.length(); j++){
            curr[i+j] = '*';
        }
    }
    
    int findStampIndex(string& curr, string& stamp){
        
        for(int i=0; i<=curr.length()-stamp.length(); i++){
            
            int j=0; // for stamp
            int s = i; // for curr
            bool notStarChar = false;
            
            while(j < stamp.length() && s < curr.length() && (curr[s] == '*' || curr[s] == stamp[j])){
                if(curr[s] != '*') notStarChar = true;
                s++;
                j++;
            }
            
            if(j == stamp.length() and notStarChar){
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
            
            int stampIndex = findStampIndex(curr, stamp);
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