class Solution {
public:
    int minPartitions(string n) {
        
        int maxDigit=0;
        for(int i=0; i<n.length(); i++){
            if(n[i] == '9') return 9;
            maxDigit = max(n[i]-'0', maxDigit);
        }
        
        return maxDigit;
    }
};