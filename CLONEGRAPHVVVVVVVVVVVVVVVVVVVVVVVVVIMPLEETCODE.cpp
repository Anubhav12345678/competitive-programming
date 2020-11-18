/*
// Definition for a Node.
class Node {
public:https://leetcode.com/problems/clone-graph/discuss/
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        unordered_map<Node*,Node*> mp;
        Node* cpy = new Node(node->val,{});
        mp[node] = cpy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto n: cur->neighbors){
                if(mp.find(n)==mp.end()){
                    Node* p = new Node(n->val,{});
                    mp[n]=p;
                    q.push(n);
                }
                mp[cur]->neighbors.push_back(mp[n]);
            }
        }
        return cpy;
        
    }
};


/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node 
with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of 
neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference 
to the cloned graph.




*/

//dfs
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(mp.find(node)==mp.end()){
            mp[node] = new Node(node->val,{});
            for(auto cur:node->neighbors){
                mp[node] -> neighbors.push_back(cloneGraph(cur));
            }
        }
        return mp[node];
    }

private:
    unordered_map<Node*,Node*> mp;
};