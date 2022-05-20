class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length() < b.length()){
            swap(a, b);
        }
        
        string s1 = a;
        string s2 = b;
        
        //cout<< s1 <<" "<<s2<<endl;
        
        reverse(s1.begin(), s1.end()); // prefer a to be longest string
        reverse(s2.begin(), s2.end());

        int i=0; // s1
        int j=0; // s2

        char carry = '0';
        string result="";

        while(i<s1.length() && j<s2.length()){

            if(s1[i] == '1' && s2[j] == '1'){
                if(carry == '1'){
                    result += '1';
                    carry = '1';
                }
                else{
                    result += '0';
                    carry = '1';
                }
            }

            else if(s1[i] == '0' && s2[j] == '0'){
                if(carry == '1'){
                    result += '1';
                    carry = '0';
                }
                else{
                    result += '0';
                }
            }

            else if(s1[i] == '0' || s2[j] == '1'){
                if(carry == '1'){
                    result += '0';
                    carry = '1';
                }
                else{
                    result += '1';
                }
            }
            
            else if(s1[i] == '1' || s2[j] == '0'){
                if(carry == '1'){
                    result += '0';
                    carry = '1';
                }
                else{
                    result += '1';
                }
            }
            i++;
            j++;
        }

        while(i<s1.length()){
            if(s1[i] == '1'){
                if(carry == '1'){
                    result += '0';
                    carry = '1';
                }
                else{
                    result += '1';
                    carry = '0';
                }
            }
            else{
                if(carry == '1'){
                    result += '1';
                    carry = '0';
                }
                else{
                    result += '0';
                    carry = '0';
                }
            }
            i++;
        }
        
        if(carry == '1'){
            result += '1';
        }
    

        reverse(result.begin(), result.end());
        return result;
    }
};