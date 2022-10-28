class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        Map<String, ArrayList<String>> map = new HashMap<>();
        
        for(String s : strs){
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            
            String tmp = String.valueOf(ca);
            if(map.containsKey(tmp) == false){
                map.put(tmp, new ArrayList<>());
            }
            
            map.get(tmp).add(s);
        }
        
        return new ArrayList<>(map.values());
    }
}