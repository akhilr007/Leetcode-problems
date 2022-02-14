class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int no_of_boats=0;
        
        int i=0;
        int j=people.size()-1;
        
        while(i<=j){
            
            if(people[i]+people[j] <= limit){
                no_of_boats++;
                i++;
                j--;
            }
            else if(people[i] + people[j] > limit){
                no_of_boats++;
                j--;
            }
        }
        
        return no_of_boats;
    }
};