class Solution {
    public int minMutation(String start, String end, String[] bank) {
        
        if(start.equals(end)) return 0;
        
        HashSet<String> visited = new HashSet<>();
        HashSet<String> wordsAllowed = new HashSet<>();
        
        for(String s: bank) wordsAllowed.add(s);
        
        char[] charset = new char[] {'A', 'C', 'G', 'T'};
        
        Queue<String> q= new LinkedList<>();
        q.offer(start);
        visited.add(start);
        
        int level=0;
        while(q.size()>0){
            
            int size=q.size();
            while(size-- > 0){
                
                String temp = q.poll();
                char[] str = temp.toCharArray();
                
                for(int i=0; i<str.length; i++){
                    char oldChar = str[i];
                    for(char c : charset){
                        
                        str[i] = c;
                        String s = new String(str);
                        
                        if(wordsAllowed.contains(s) && !visited.contains(s)){
                            
                            if(s.equals(end)) return level+1;
                            
                            System.out.println(s);
                            q.offer(s);
                            visited.add(s);
                        }
                    }
                    
                    str[i] = oldChar;
                }
            }
            
            level++;
        }  
        
        return -1;
    }
}