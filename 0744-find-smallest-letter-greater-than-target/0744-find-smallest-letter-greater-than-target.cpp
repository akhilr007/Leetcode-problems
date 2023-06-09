class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size();
        
        int index = upper_bound(begin(letters), end(letters), target) - begin(letters);
        
        if(index == n)
            return letters[0];
        
        return letters[index];
    }
};