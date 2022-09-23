class Solution {
public:
    int concatenatedBinary(int n) {
        
        string res="";
        int MOD = 1e9+7;
        
        for(int i=1; i<=n; i++){
            string binary = bitset<32>(i).to_string();
            binary.erase(0, binary.find_first_not_of('0'));
            res += binary;
        }
        
        int decimalValue=0;
        int base = 1;
        for(int i=res.size()-1; i>=0; i--){
            
            int lastDigit = res[i]-'0';
            
            decimalValue = ((decimalValue%MOD) + (lastDigit * base)%MOD) % MOD;
            base = (base * 2) % MOD;
        }
        
        return decimalValue;
    }
};