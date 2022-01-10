class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // we will be using moore voting algorithm concept
        // at most 2 elements can have greater than n/3 
        
        int m1=-1; // potential majority element 1 ,i.e pme1
        int c1=0; // count of pme1
        
        int m2=-1; // potential majority element 2, i.e pme2
        int c2=0; // count of pme2
        
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            
            if(nums[i] == m1) {
                c1++;
            }
            else if(nums[i] == m2){
                c2++;
            }
            else if(c1 == 0){
                m1 = nums[i];
                c1=1;
            }
            else if(c2 == 0){
                m2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        int freq1=0; // frequency of pme1
        int freq2=0; // frequency of pme2
        
        for(int i=0; i<n; i++){
            if(nums[i] == m1){
                freq1++;
            }
            else if(nums[i] == m2){
                freq2++;
            }
        }
        
        vector<int> ans;
        cout<<freq1<<" "<<freq2<<endl;
        if(freq1 > n/3) ans.push_back(m1);
        if(freq2 > n/3) ans.push_back(m2);
        
        return ans;
        
        
        
    }
};