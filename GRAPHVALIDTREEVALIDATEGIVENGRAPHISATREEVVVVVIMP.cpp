/*

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a
 function to check whether these edges make up a valid tree.
For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the
 same as [1, 0]and thus will not appear together in edges.



*/

//union find
class Solution {
    private int[] parent;
    private int[] size;
    
    public boolean validTree(int n, int[][] edges) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size = new int[n];
        Arrays.fill(size, 1);
        
        for (int[] edge : edges) {
            if (!union(edge[0], edge[1])) {
                return false;
            }
        }
        return edges.length == n - 1;
    }
    
    private boolean union(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);
        
        if (p1 == p2) {
            return false;
        }
        if (size[p1] < size[p2]) {
            parent[p1] = p2;
            size[p2]++;
        } else {
            parent[p2] = p1;
            size[p1]++;
        }
        return true;
    }
    
    private int find(int v) {
        while (v != parent[v]) {
            parent[v] = find(parent[parent[v]]);
            v = parent[v];
        }
        return v;
    }
}

//DFS

public class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length == 0) {
            return n == 1;
        }
        if (n != edges.length + 1) {
            return false;
        }
        
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new HashSet<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        Set<Integer> visited = new HashSet<>();
        if (hasCycle(0, -1, graph, visited)) {
            return false;
        }
        return visited.size() == n;
    }
    
    private boolean hasCycle(int node, int parent, Map<Integer, Set<Integer>> graph, Set<Integer> visited) {
        visited.add(node);
        for (int neighbor : graph.get(node)) {
            if (neighbor != parent && visited.contains(neighbor)) {
                return true;
            }
            if (!visited.contains(neighbor) && hasCycle(neighbor, node, graph, visited)) {
                return true;
            }
        }
        return false;
    }
}