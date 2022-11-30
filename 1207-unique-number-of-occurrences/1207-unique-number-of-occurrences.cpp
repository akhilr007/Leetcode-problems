class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        
        Set<Integer> set = new HashSet<>();
        Map<Integer, Integer> map = new HashMap<>();
        for(int number: arr){
            map.put(number, map.getOrDefault(number, 0) + 1);
        }
        
        for(int key: map.keySet()){
            if(set.contains(map.get(key))==true) return false;
            set.add(map.get(key));
        }
        
        return true;
    }
}