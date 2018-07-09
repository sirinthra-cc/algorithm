vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    // assuming graph of nxn
    // finding all-pair shortest path
    // O(V^3)
    int num_node = graph.size();
    for(int k=0;k<num_node;k++)  // ทางผ่าน
        for(int i=0;i<num_node;i++) // จุดเริ่มต้น
            for(int j=0;j<num_node;j++) // จุดหมาย
                // ถ้า จุดเริ่มต้น -> ทางผ่าน -> จุดหมาย สั้นกว่า จุดเริ่มต้น -> จุดหมาย ก็แก้ค่า
                if(graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j]

}