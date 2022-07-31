class NumArray {
public:
    vector<int> st;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n, 0);
        buildSegmentTree(0, n-1, 0, nums);
    }
    
    void buildSegmentTree(int start, int end, int node, vector<int>& nums){
        
        // base case
        if(start == end){
            st[node] = nums[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        
        // left subtree of segment tree
        buildSegmentTree(start, mid, 2*node+1, nums);
        
        // right subtree of segment tree
        buildSegmentTree(mid+1, end, 2*node+2, nums);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
    
    void updateSegmentTree(int start, int end, int node, int index, int val){
        
        if(start == end){
            st[node] = val;
            return;
        }
        
        int mid = start + (end - start)/2;
        
        if(index <= mid){
            updateSegmentTree(start, mid, 2*node+1, index, val);
        }
        else{
            updateSegmentTree(mid+1, end, 2*node+2, index, val);
        }
        
        st[node] = st[2*node+1] + st[2*node+2];
        return;
    }
    
    void update(int index, int val) {
        updateSegmentTree(0, n-1, 0, index, val);
    }
    
    int queryRange(int start, int end, int node, int left, int right){
        
        // no overlapping case
        if(start > right or end < left) return 0;
        
        // complete overlapping case
        if(start >= left and end <= right){
            return st[node];
        }
        
        int mid = start + (end - start) / 2;
        
        int q1 = queryRange(start, mid, 2*node+1, left, right);
        int q2 = queryRange(mid+1, end, 2*node+2, left, right);
        
        return q1+q2;
    }
    
    int sumRange(int left, int right) {
        return queryRange(0, n-1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */