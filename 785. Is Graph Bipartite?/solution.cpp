/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
 

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> colors(n, 0); 
        //three states
        //0: not painted
        //1: color 1
        //-1: color 2
        for(int i= 0; i< n; i++){
            if(colors[i] == 0 && !paint(graph, colors, i, 1))
                return false;
        }
        return true;
    }
    
    bool paint(vector<vector<int>>& graph, vector<int>& colors, int index, int color){
        if(colors[index] != 0)
            return colors[index] == color;
        
        //color = 0, means not painted yet. Assign color to node[index]
        colors[index]= color;
        
        for(int i= 0; i< graph[index].size(); i++){
            if(!paint(graph, colors, graph[index][i], -color)) return false;
        }
        return true;
    }
};