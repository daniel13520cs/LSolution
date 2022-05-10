Directed Graph => use DFS with visited state to detect cycle
Undirected Graph => use DFS with visited state and (int) prev to detect cycle
Unconnected Graph => use DFS with visited/visiting state and prev to detect cycle
DAG => use Topological sort and indegrees to get the orders
Tree is a acyclic Connected Graph 