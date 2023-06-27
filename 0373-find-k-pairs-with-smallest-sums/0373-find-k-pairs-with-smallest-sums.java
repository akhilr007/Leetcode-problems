class Pair{

    int sum;
    int i;
    int j;
    Pair(int sum, int i, int j){
        this.sum = sum;
        this.i = i;
        this.j = j;
    }
}

class Solution {
    public List<List<Integer>> kSmallestPairs(int[] a, int[] b, int k) {
        
        List<List<Integer>> result = new ArrayList<>();
        int n = a.length;
        int m = b.length;
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> p2.sum - p1.sum);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = a[i] + b[j];
                
                if(pq.size()<k){
                    pq.offer(new Pair(sum, i, j));
                }
                else if(pq.peek().sum>sum){
                    pq.poll();
                    pq.offer(new Pair(sum, i, j));
                }
                else{
                    break;
                }
            }
        }
        
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            List<Integer> list = new ArrayList<>();
            list.add(a[p.i]);
            list.add(b[p.j]);
            result.add(list);
        }
        
        return result;
    }
}