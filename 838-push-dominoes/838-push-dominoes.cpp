class Solution {
public:
    string pushDominoes(string s) {
        
        int n = s.length();
        
        int nearestLeft=-1;
        vector<int> left(n);
        
        for(int i=n-1; i>=0; i--){
            
            if(s[i] == 'L'){
                nearestLeft = i;
            }
            else if(s[i] == 'R'){
                nearestLeft = -1;
            }
            left[i] = nearestLeft;
        }
        
        int nearestRight = -1;
        vector<int> right(n);
        
        for(int i=0; i<n; i++){
            
            if(s[i]=='R'){
                nearestRight = i;
            }
            else if(s[i]=='L'){
                nearestRight = -1;
            }
            right[i] = nearestRight;
        }
        
        string ans="";
        for(int i=0; i<n; i++){
            
            if(s[i]=='.'){
                
                int nearLeft = left[i];
                int nearRight = right[i];
                
                int leftDiff = nearLeft == -1 ? INT_MAX : abs(nearLeft-i);
                int rightDiff = nearRight == -1 ? INT_MAX : abs(nearRight-i);
                
                if(leftDiff == rightDiff){
                    ans += '.';
                }
                else if(leftDiff < rightDiff){
                    ans += 'L';
                }
                else{
                    ans += 'R';
                }
                
            }
            else{
                ans += s[i];
            }
        }
        
        return ans;
    }
};