class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp;
        unordered_map<char, bool> used;

        for(int i=0; i<s.length(); i++){

            if(mp.find(s[i]) != mp.end()){

                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(used.find(t[i]) != used.end()){
                    return false;
                }
                else{
                    mp[s[i]] = t[i];
                    used[t[i]] = true;
                }
            }
        }

        return true;
    }
};