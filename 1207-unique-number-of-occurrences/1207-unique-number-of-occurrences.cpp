class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int N=2001;
        int count[2001]={0};
        for(int i=0; i<arr.size(); i++){
            count[arr[i] + 1000]++;
        }
        
        sort(count, count+N);
        for(int i=1; i<N-1; i++){
            if(count[i] > 0 && (count[i] == count[i+1])) return false;
        }
        
        return true;
    }
};