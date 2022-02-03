class Solution {
public:
    string pushDominoes(string str) {
        
        int n = str.length();
    
    vector<int> left(n);
    int nearestLeft = -1;
    
    for(int i=n-1; i>=0; i--){
        
        if(str[i] == 'L'){
            nearestLeft = i;
        }
        else if(str[i] == 'R'){
            nearestLeft = -1;
        }
        
        left[i] = nearestLeft;
    }
    
    vector<int> right(n);
    int nearestRight = -1;
    
    for(int i=0; i<n; i++){
        
        if(str[i] == 'R'){
            nearestRight = i;
        }
        else if(str[i] == 'L'){
            nearestRight = -1;
        }
        right[i] = nearestRight;
    }
    
    string ans ="";
    
    for(int i=0; i<n; i++){
        
        if(str[i] == '.'){
            
            int nearLeft = left[i];
            int nearRight = right[i];
            
            int leftDiff = nearLeft == -1 ? INT_MAX : abs(nearLeft - i);
            int rightDiff = nearRight == -1 ? INT_MAX : abs(nearRight - i);
            
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
            ans += str[i];
        }
    }
    
    return ans;
    }
};