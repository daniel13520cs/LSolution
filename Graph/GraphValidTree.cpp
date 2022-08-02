// Copyright 2022 <CHIHCHIEN>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// DFS
class Solution {
 private:
    vector<int> state;

 public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    enum {UNVISITED, VISITING, VISITED};
    bool validTree(int n, vector<vector<int> >& edges) {
        // write your code here
        vector<vector<int> > adj(n, vector<int>());
        state = vector<int>(n, UNVISITED);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (isCyclic(0, &adj, -1)) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (state[i] == UNVISITED) {
                cout << i;
                return false;
            }
        }
        return true;
    }

    bool isCyclic(int cur, vector<vector<int> >* adj, int prev) {
        if (state[cur] == VISITED) {
            return true;
        }
        state[cur] = VISITED;
        for (int v : adj->at(cur)) {
            if (v != prev) {
                if (isCyclic(v, adj, cur)) {
                    return true;
                }
            }
        }
        return false;
    }
};
