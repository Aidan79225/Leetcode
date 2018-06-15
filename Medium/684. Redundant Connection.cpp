class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1,-1);
        for(vector<int> edge : edges){
            int parent1 = findParent(edge[0], parents);
            int parent2 = findParent(edge[1], parents);
            if(parent1 == parent2){
                return edge;
            }else{
                unionNode(parent1, parent2, parents);
            }
        }
        return vector<int>();
    }
    
    int findParent(int node, vector<int>& parents){
        if(parents[node] == -1)return node;
        else return findParent(parents[node], parents);
    }
    
    void unionNode(int node1, int node2, vector<int>& parents){
        parents[node2] = node1;
    }
    
    
};
