class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream ss(path);
        string temp;
        vector<string> words;
        
        while(getline(ss, temp, '/')){
            
            if(temp == "" or temp == ".") continue;
            
            else if(temp == ".."){
                if(words.size()>0) words.pop_back();
            }
            else{
                words.push_back(temp);
            }
        }
        
        if(words.size()==0) return "/";
        
        string result="";
        for(auto s : words){
            result += "/" + s;
        }
        
        return result;
        
    }
};