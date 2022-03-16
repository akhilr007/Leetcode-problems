class Solution {
public:
    int myAtoi(string s) {
        
        /*
        valid-->
        '   43' -> 43
        '  -42' -> 42
        '42' -> 42
        '32132sdjffj' -> 32132
        '9297489274723947379' ->INT_MAX;
        '-23423432984932497347' -> INT_MIN
        
        invalid->
        'sfhsdhf47987324' -> 0
        '' -> 0
        +hsdkfhsdk3789789324 -> 0
        
        */
        
        int i=0;
        int n=s.length();
        int res=0;
        
        // for whitespaces
        while(i<n && s[i] == ' '){
            i++;
        }
        
        // for -ve and +ve
        int negative = 1;
        if(i<n && s[i] == '-'){
            negative = -1;
            i++;
        }
        else if(i<n && s[i] == '+') i++;
        
        // check numbers;
        set<char> st;
        for(int i=0; i<=9; i++) st.insert(i+'0');
        
        while(i<n && st.find(s[i]) != st.end()){
            
            if(res > INT_MAX/10 || (res == INT_MAX/10 && s[i] > '7')){
                if(negative==1) return INT_MAX;
                else return INT_MIN;
            }
            
            res = res*10+(s[i]-'0');
            i++;
        }
        
        return res*negative;
        
        
        
    }
};