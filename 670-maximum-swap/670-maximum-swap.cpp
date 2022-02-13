class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int n=s.length();
        
//         vector<int> rmax(n);
//         rmax[n-1] = n-1;
        
//         for(int i=n-2; i>=0; i--){
//             int digit = s[i]-'0';
//             int nextDigit = s[rmax[i+1]]-'0';
//             if(digit > nextDigit){
//                 rmax[i] = i;
//             }
//             else rmax[i] = rmax[i+1];
//         }
        
        
//         for(int i=0; i<n; i++){
//             int digit = s[i]-'0';
//             if(digit < s[rmax[i]]-'0'){
//                 swap(s[i], s[rmax[i]]);
//                 break;
//             }
//         }
        
        int lastIndex[10]={0};
        
        // 1. prepare last indexes occurences
        for(int i=0; i<n; i++){
            int digit = s[i]-'0';
            lastIndex[digit]=i;
        }
        
        //2 . figure at which position to do swapping
        bool flag = false;
        for(int i=0; i<n; i++){
            int digit = s[i]-'0';
            for(int j=9; j>digit; j--){
                if(i < lastIndex[j]){
                    swap(s[i], s[lastIndex[j]]);
                    flag = true;
                    break;
                }
            }
            
            if(flag == true) break;
        }
        
        
        return stoi(s);
    }
};