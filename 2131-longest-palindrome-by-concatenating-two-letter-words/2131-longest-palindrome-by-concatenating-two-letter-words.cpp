class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> FMap; // frequency map of words
        for(string& word: words) FMap[word]++;
        
        bool centreUsed = false;
        int longestPalindromeString=0;
        // start iterating in words one by one
        for(string& word: words){
            
            string rev = word;
            reverse(rev.begin(), rev.end());
            
            if(word != rev){ // like ab and ba
                if(FMap[word]>0 && FMap[rev]>0){
                    longestPalindromeString += 4;
                    FMap[word]--;
                    FMap[rev]--;
                }
            }
            else{ // like aa 
                if(FMap[word] >= 2){
                    longestPalindromeString += 4;
                    FMap[word] -= 2;
                }
                else if(FMap[word] == 1 && centreUsed == false){
                    longestPalindromeString += 2;
                    FMap[word]--;
                    centreUsed = true;
                }
            }
        }
        
        return longestPalindromeString;
    }
};