class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> hashmap;
        for(int i=0; i<magazine.length(); i++){
            hashmap[magazine[i]]++;
        }
        
        int count = 0;
        for(int i=0; i<ransomNote.length(); i++){
            if(hashmap.find(ransomNote[i]) != hashmap.end()){
                count++;
                hashmap[ransomNote[i]]--;
                if(hashmap[ransomNote[i]] == 0){
                    hashmap.erase(ransomNote[i]);
                }
            }
        }
        
        return count == ransomNote.length();
    }
};