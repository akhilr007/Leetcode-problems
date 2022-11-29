class RandomizedSet {
    
    private HashSet<Integer> set;
    public RandomizedSet() {
        set = new HashSet<>();
    }
    
    public boolean insert(int val) {
        if(set.contains(val)==true) return false;
        set.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(set.contains(val)==false) return false;
        set.remove(val);
        return true;
    }
    
    public int getRandom() {
        
        Integer[] arr = set.toArray(new Integer[set.size()]);
        Random rand = new Random();
        int randomNumber = rand.nextInt(set.size());
        return arr[randomNumber];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */