class Solution{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){

        vector<string> result;

        int i=0;

        while(i<words.size()){

            int wordCharCount = words[i].length();
            int j = i+1; // next word index;

            int normalSpaces=0; // normal spaces used
            while(j<words.size() and (wordCharCount + words[j].length() + 1 <= maxWidth)){
                wordCharCount += words[j].length() + 1;
                normalSpaces++;
                j++;
            }

            // calculate total spaces left if we consider only characters
            int totalSpaces = maxWidth - wordCharCount + normalSpaces;
            // suppose we have a sentence
            // i am a boy then spaces where we can add space are 3 that is total words-1
            int distributeSpaces = j-i-1; // 

            int minSpace = distributeSpaces == 0 ? 0 : totalSpaces / distributeSpaces;
            int extraSpace = distributeSpaces == 0 ? 0 : totalSpaces % distributeSpaces;
            
            if(j == words.size()){
                minSpace = 1;
                extraSpace=0;
            }

            string s="";
            for(int k=i; k<j; k++){
                s += words[k];

                // if it is the last word for the line then dont add space
                if(k == j-1) break;

                for(int e=0; e<minSpace; e++){
                    s += " ";
                }
                if(extraSpace > 0){
                    s += " ";
                    extraSpace--;
                }
            }

            while(s.length() < maxWidth) s += " ";

            result.push_back(s);
            i=j;
        }

        return result;
    }
};