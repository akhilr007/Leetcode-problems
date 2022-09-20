class Solution {
private:
    bool isDigit(string& s){
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i]) == false) return false;
        }
        
        return true;
    }
    
    bool isValid(string& s){
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if((ch >= 'a' && ch <= 'f') or (ch >= 'A' && ch <= 'F') or isdigit(ch)){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
public:
    string validIPAddress(string queryIP) {
        
        if(queryIP.length() == 0) return "Neither";
        
        if(queryIP[0] == '.' or queryIP[queryIP.length()-1] == '.' or queryIP[0] == ':' or queryIP[queryIP.length()-1] == ':') return "Neither";
        
        stringstream ss(queryIP);
        string s;
        
        int count=0;
        while(getline(ss, s, '.')){
            count++;
        }
        
        if(count == 4){
            // ipv4
            stringstream ss(queryIP);
            string token;
            
            bool flag = true;
            count = 0;
            while(getline(ss, token, '.')){
                
                if(token.length()>3){
                flag = false;
                break;
            }
                //cout<<token;
                // case -> 127...1
                if(token.length() == 0 || !isDigit(token)){
                    flag = false;
                    break;
                }
                
                int tokenInt = stoi(token);
                // case -> 0000 -- not valid ipv4
                if(tokenInt == 0 && token.length() > 1){
                    flag = false;
                    break;
                }
                
                // case -> 0123 -- not valid ipv4
                if(tokenInt > 0 && (token.length()>1 && token[0] == '0')){
                    flag = false;
                    break;
                }
                
                if(tokenInt >= 0 && tokenInt <= 255) flag = true;
                else{
                    flag = false;
                    break;
                }
                
                count++;
            }
            
            if (count == 4 && flag == true) return "IPv4";
        }
        else if(count != 4){
            //ipv6
            stringstream ss(queryIP);
            string token;
            
            count=0;
            while(getline(ss, token, ':')){
                cout<<token<<" ";
                bool isvalid = isValid(token);
                if(isvalid == false or token.length()>4 or token.length()<1) return "Neither";
                count++;
            }
            
            if (count == 8) return "IPv6";
            else return "Neither";
        }
        
        return "Neither";
    }
};