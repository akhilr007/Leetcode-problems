class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> files;
        vector<vector<string>> ans;
        
        for(auto& path: paths){
            stringstream ss(path);
            string s, dir, file, content;
            ss >> dir; // dir -> file path
            //cout<<"d: "<<dir<<" ";
            while(ss >> s){
                // s -> file.txt(content)
                auto it = s.find('(');
                file = s.substr(0, it);
                content = s.substr(it);
                files[content].emplace_back(dir+"/"+file);
            }
        }
        
        for(auto& content: files){
            if(content.second.size()>1){
                ans.push_back(files[content.first]);
            }
        }
        return ans;
    }
};