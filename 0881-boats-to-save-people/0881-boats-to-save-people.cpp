class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        sort(begin(people), end(people));
        
        int i=0;
        int j=n-1;
        
        int cnt=0;
        while(i <= j){
            
            if(people[i] + people[j] <= limit){
                cnt++;
                i++;
                j--;
            }
            else if(people[i] + people[j] > limit){
                
                cnt++;
                j--;
            }
        }
        
        return cnt;
    }
};