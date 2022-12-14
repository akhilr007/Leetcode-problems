class Pair{
    String word;
    int steps;
    
    Pair(String word, int steps){
        this.word = word;
        this.steps = steps;
    }
}

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        HashSet<String> set = new HashSet<>();
        for(String word: wordList){
            set.add(word);
        }
        
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(beginWord, 1));
        
        set.remove(beginWord);
        
        while(q.size()>0){
            
            String word = q.peek().word;
            int steps = q.peek().steps;
            q.remove();
            
            if(word.equals(endWord)) return steps;
            
            for(int i=0; i<word.length(); i++){
                char[] temp = word.toCharArray();
                char originalChar = temp[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    temp[i] = ch;
                    String str = new String(temp);
                    if(set.contains(str)==true){
                        set.remove(str);
                        q.add(new Pair(str, steps + 1));
                    }
                }
                
                temp[i] = originalChar;
            }
        }
        
        return 0;
    }
}