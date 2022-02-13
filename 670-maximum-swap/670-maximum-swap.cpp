class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int n=s.length();
        
        vector<int> rmax(n);
        rmax[n-1] = n-1;
        
        for(int i=n-2; i>=0; i--){
            int digit = s[i]-'0';
            int nextDigit = s[rmax[i+1]]-'0';
            if(digit > nextDigit){
                rmax[i] = i;
            }
            else rmax[i] = rmax[i+1];
        }
        
        
        for(int i=0; i<n; i++){
            int digit = s[i]-'0';
            if(digit < s[rmax[i]]-'0'){
                swap(s[i], s[rmax[i]]);
                break;
            }
        }
        
        return stoi(s);
    }
};