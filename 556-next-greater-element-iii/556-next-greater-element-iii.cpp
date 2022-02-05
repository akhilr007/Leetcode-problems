class Solution {
public:
    int nextGreaterElement(int n) {
        
        string num = to_string(n);
        
        int i=num.length()-1;
        
        // find dip 
        while(i>0){
            if(num[i-1] >= num[i]){
                i--;
            }
            else{
                break;
            }
        }
        
        // if i is at 0th index then there is no dip so no permutation to find nge
        if(i==0){
            return -1;
        }
        
        int dip = i-1;
        int justLarger = -1;
        
        for(int j=num.length()-1; j>=dip+1; j--){
            if(num[j] > num[dip]){
                justLarger = j;
                break;
            }
        }
        
        swap(num[dip], num[justLarger]);
        reverse(num.begin()+dip+1, num.end());
        
        
        long no = stol(num);
        if(no > INT_MAX) return -1;
        return no;
        
    }
};