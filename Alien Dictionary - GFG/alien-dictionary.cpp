// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        
        // make all char indegree 0
        for(int i=0; i<N; i++){
            for(auto ch : dict[i]){
                indegree[ch]=0;
            }
        }
        
        for(int i=0; i<N-1; i++){
            string curr = dict[i];
            string next = dict[i+1];
            
            int len = min(curr.length(), next.length());
            for(int j=0; j<len; j++){
                
                char ch1 = curr[j];
                char ch2 = next[j];
                
                if(ch1 != ch2){
                    
                    unordered_set<char> set;
                    
                    if(graph.find(ch1) != graph.end()){
                        
                        set = graph[ch1];
                        
                        if(set.find(ch2) == set.end()){
                            set.insert(ch2);
                            indegree[ch2]++;
                            graph[ch1] = set;
                        }
                    }
                    
                    else{
                        
                        set.insert(ch2);
                        indegree[ch2]++;
                        graph[ch1] = set;
                    }
                    
                    break;
                }
            }
        }
        
        queue<char> q;
        
        for(auto it : indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        
        int count=0;
        string ans="";
        
        while(q.size()>0){
            
            char rem = q.front();
            q.pop();
            
            count++;
            ans += rem;
            
            if(graph.find(rem) != graph.end()){
                unordered_set<char> nbrs = graph[rem];
                
                for(auto nbr : nbrs){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
        }
        
        if(count == indegree.size()){
            return ans;
        }
        else{
            return "";
        }
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends