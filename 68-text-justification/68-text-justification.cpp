class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        
        int i=0;
        while(i<words.size()){
            
            int wordCharCount = words[i].length();
            int j=i+1;
            
            int normalSpaces=0;
            while(j<words.size() and (wordCharCount+words[j].length()+1 <= maxWidth)){
                wordCharCount += words[j].length()+1;
                normalSpaces++;
                j++;
            }
            
            int totalSpaces = maxWidth - wordCharCount + normalSpaces;
            int distributeSpaces = j-i-1; // i am a boy so 3 spaces are there between words
            //cout<<totalSpaces<<" "<<distributeSpaces<<" ";
            
            int minSpace = distributeSpaces == 0 ? 0 : totalSpaces / distributeSpaces;
            int extraSpace = distributeSpaces == 0 ? 0:  totalSpaces % distributeSpaces;
            //cout<<minSpace<<" "<<extraSpace<<endl;
            
            // for last line
            if(j == words.size()){
                minSpace = 1;
                extraSpace = 0;
            }
            
            string s="";
            for(int k=i; k<j; k++){
                
                s += words[k];
               // cout<<s<<endl;
                
                if(k == j-1){
                    break;
                }
                
                for(int e=0; e<minSpace; e++){
                    s += " ";
                }
                if(extraSpace > 0){
                    s += " ";
                    extraSpace--;
                }
            }
            
            // the length of each line should be equal to maxwidth
            while(s.length() < maxWidth){
                s += " ";
            }
            
            result.push_back(s);
            i=j;
        }
        
        return result;
    }
};