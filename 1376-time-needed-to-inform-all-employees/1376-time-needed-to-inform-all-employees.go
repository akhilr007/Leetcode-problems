func dfs(manager int, adj map[int][] int, informTime []int, count int, result *int){
    
    if count > *result {
        *result = count
    }
    
    for _, employee := range adj[manager] {
        
        dfs(employee, adj, informTime, count + informTime[manager], result)
    }
}

func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
    
    adj := map[int][]int{}
    
    for i:=0; i<n; i++ {
        
        managerID := manager[i]
        employeeID := i
        
        adj[managerID] = append(adj[managerID], employeeID)
    }
    
    result := 0
    count := 0
    
    dfs(headID, adj, informTime, count, &result);
    
    return result
}