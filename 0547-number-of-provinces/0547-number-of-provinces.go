func dfs(node int, adj map[int][] int, visited []bool){
    
    visited[node] = true
    
    for _, adjNode := range adj[node] {
        if visited[adjNode] == false {
            dfs(adjNode, adj, visited)
        }
    }
}

func findCircleNum(isConnected [][]int) int {
    
    n:= len(isConnected)
    
    adj := map[int][]int {}
    
    for i:=0; i<n; i++ {
        for j:=0; j<n; j++ {
            if i == j {
                continue
            }
            
            if isConnected[i][j]==1{
                adj[i] = append(adj[i], j)
                adj[j] = append(adj[j], i)
            }
            
        }
    }
    
    visited := make([]bool, n)
    for i:=0; i<n; i++{
        visited[i] = false
    }
    
    count := 0
    for i:=0; i<n; i++{
        if visited[i]==false{
            dfs(i, adj, visited)
            count++
        }
    }
    
    return count
}

