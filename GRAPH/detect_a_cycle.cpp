//BFS
//TC- O(N+2E) for every node we are traversing through all its adjacent node
//SC- O(N)

bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }

//DFS
//TC- O(N+2E)- all the adjacent node and the summation of adjacent node is 2E
//SC- 0(N)-visited array+O(N)- auxillary space
bool dfs_detect(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
//for dfs        if(dfs_detect(i, -1, vis, adj) == true) return true;
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
