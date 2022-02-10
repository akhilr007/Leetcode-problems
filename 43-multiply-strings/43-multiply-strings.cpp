class Solution {
public:
    string multiply(string num1, string num2) {
        
        // always want my num1 should be greater than num2
        if(num1.length() < num2.length()) swap(num1, num2);
        
        int l1=num1.length();
        int l2=num2.length();
        
        if((l1==1 && num1[l1-1] == '0') || (l2==1 && num2[l2-1] == '0')) return "0";
        
        vector<int> res(l1+l2, 0);
        
        int i=l2-1;
        int pf=0; // power factor
        
        while(i>=0){
            
            int ival = num2[i]-'0';
            i--;
            
            int j = l1-1;
            int c = 0; // carry
            int k = res.size()-1-pf;
            
            while(j>=0 || c!=0){
                int jval = j>=0 ? num1[j] - '0' : 0;
                j--;
                
                int prod = ival * jval + c + res[k];
                
                res[k] = prod % 10;
                c = prod/10;
                k--;
            }
            
            pf++;
        }
        
        // for leading zeros
        string str="";
        bool f=false;
        for(int val : res){
            if(val == 0 && f==false){
                continue;
            }
            else{
                f=true;
                str += val+'0';
            }
        }
        return str;
    }
};