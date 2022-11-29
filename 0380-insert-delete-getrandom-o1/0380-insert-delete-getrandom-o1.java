class RandomizedSet {
    
    private List<Integer> nums;
    private Map<Integer, Integer> indexMap;

    public RandomizedSet() {
        nums = new ArrayList<>();
        indexMap = new HashMap<>();
    }
    
    public boolean insert(int val) {
        
        if(indexMap.containsKey(val) == true) return false;
        
        nums.add(val);
        indexMap.put(val, nums.size()-1);
        return true;
    }
    
    public boolean remove(int val) {
        
        if(indexMap.containsKey(val) == false) return false;
        
        int idx = indexMap.get(val);
        int lastElement = nums.get(nums.size()-1);
        nums.set(nums.size()-1, val);
        
        nums.set(idx, lastElement);
        indexMap.put(lastElement, idx);
        
        nums.remove(nums.size()-1);
        indexMap.remove(val);
        return true;
    }
    
    public int getRandom() {
        
        Random random = new Random();
        int randomIndex = random.nextInt(nums.size());
        return nums.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */