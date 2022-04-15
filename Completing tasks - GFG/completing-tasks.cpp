// { Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        
        unordered_set<int> s;
        vector<int> t1, t2;
        
        for(int i=0; i<m; i++){
            s.insert(arr[i]); // 2 5 6 7 9 4
        }
        
        bool flag=false;
        for(int i=1; i<=n; i++){
            if(s.find(i) != s.end()){
                continue;
            }
            else{
                
                if(flag == false){
                    t1.push_back(i);
                    flag=true;
                }
                else{
                    t2.push_back(i);
                    flag=false;
                }
            }
        }
        
        pair<vector<int>, vector<int>> p;
        p.first = t1;
        p.second = t2;
        return p;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends