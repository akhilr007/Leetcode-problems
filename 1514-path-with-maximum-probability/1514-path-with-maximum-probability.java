class QPair{
    int node;
    double p;
    QPair(int node, double p){
        this.node = node;
        this.p = p;
    }
}

class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        
        List<List<Pair<Integer, Double>>> adj = new ArrayList<>(n);
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            
            adj.get(u).add(new Pair<>(v, p));
            adj.get(v).add(new Pair<>(u, p));
        }
        
        PriorityQueue<QPair> pq = new PriorityQueue<>((q1,q2) -> Double.compare(q2.p,q1.p));
        pq.offer(new QPair(start, 1.0));
        
        double[] result = new double[n];
        result[start] = 1.0;
        
        while(!pq.isEmpty()){
            
            QPair top = pq.poll();
            int curNode = top.node;
            double curProb = top.p;
            
            for(Pair<Integer, Double> pt : adj.get(curNode)){
                
                int adjNode = pt.getKey();
                double adjProb = pt.getValue();
                
                if(curProb * adjProb > result[adjNode]){
                    result[adjNode] = curProb * adjProb;
                    pq.add(new QPair(adjNode, result[adjNode]));
                }
            }
        }
        
        return result[end];
    }
}