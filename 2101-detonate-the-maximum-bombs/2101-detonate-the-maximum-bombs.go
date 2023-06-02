func dfs(node int, adj map[int][] int, visited []bool, count *int) {
    
    visited[node] = true
    *count++
    
    for _, adjNode := range adj[node] {
        
        if visited[adjNode] == false {
            dfs(adjNode, adj, visited, count)
        }
    }
}

func maximumDetonation(bombs [][]int) int {
    
    n := len(bombs)
    
    // adjacency list
    adj := map[int][] int {}
    
    for i:=0; i<n; i++ {
        for j:=0; j<n; j++ {
            
            if i == j{
                continue
            }
            
            x1 := bombs[i][0]
            y1 := bombs[i][1]
            r1 := bombs[i][2]
            
            x2 := bombs[j][0]
            y2 := bombs[j][1]
            
            distance := (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
            
            if r1*r1 >= distance {
                adj[i] = append(adj[i], j)
            }
        }
    }
    
    visited := make([]bool, n)
    for i:=0; i<n; i++{
        visited[i] = false
    }
    
    result := 0
    for i:=0; i<n; i++{
        
        count := 0
        dfs(i, adj, visited, &count)
        
        result = int(math.Max(float64(result), float64(count)))
        
        for j:=0; j<n; j++{
            visited[j] = false
        }
    }
    
    return result
}