class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // gonna use moore voting algorithm
        // let us assume our majority element to be first element of our array
        int potential_majority_element = nums[0];
        // increase the count to 1
        int count=1;
        
        int n = nums.size();
        for(int i=1; i<n; i++){
            
            if(nums[i] == potential_majority_element){
                count++;
            }
            else{
                count--;
            }
            
            // if at any stage my count becomes zero, then make the next element to be 
            // potential majority element
            if(count == 0){
                potential_majority_element=nums[i];
                count=1;
            }
        }
        
        // now check if the potential majority eleement is actually the majority element
        // check if the count is greater than n/2 times
        
        int freq=0; // frequency of majority element
        for(int i=0; i<n; i++){
            if(nums[i] == potential_majority_element){
                freq++;
            }
        }
        
        if(freq > n/2) return potential_majority_element;
        else return -1;
        
    }
};