class DSU {
private:
    vector<int> parent, size, rank; 
public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    } 
public:
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
public:
    void unionSize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i = 0; i < m; i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        DSU MST(n + 1);
        int minWeightMst = 0;
        for(int i = 0; i < m; i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int weight = edges[i][2];
            if(MST.findPar(node1) != MST.findPar(node2)){
                MST.unionSize(node1, node2);
                minWeightMst += weight;
            }
        }
        // We have the minimum weight of MST

        vector<vector<int>> ans(2);
        for(int i = 0; i < m; i++){
            DSU letsIgnoreThisEdge(n + 1);
            int currSum = 0;
            for(int j = 0; j < m; j++){
                if(i != j){
                    int node1 = edges[j][0];
                    int node2 = edges[j][1];
                    int weight = edges[j][2];
                    if(letsIgnoreThisEdge.findPar(node1) != letsIgnoreThisEdge.findPar(node2)){
                        letsIgnoreThisEdge.unionSize(node1, node2);
                        currSum += weight;
                    }
                }
            }
            bool check = false;
            int parent = letsIgnoreThisEdge.findPar(0);
            for(int k = 1; k < n; k++){
                if(letsIgnoreThisEdge.findPar(k) != parent){
                    check = true;
                }
            }
            if(currSum > minWeightMst || check){
                ans[0].push_back(edges[i][3]);
            }
            else{
                DSU putThisEdge(n + 1);
                int node1 = edges[i][0];
                int node2 = edges[i][1];
                int weight = edges[i][2];
                int currSum = weight;
                putThisEdge.unionSize(node1, node2);
                for(int j = 0; j < m; j++){
                    if(i != j){
                        int node1 = edges[j][0];
                        int node2 = edges[j][1];
                        int weight = edges[j][2];
                        if(putThisEdge.findPar(node1) != putThisEdge.findPar(node2)){
                            putThisEdge.unionSize(node1, node2);
                            currSum += weight;
                        }
                    }
                }
                if(currSum == minWeightMst){
                    ans[1].push_back(edges[i][3]);
                }
            }
        }
        return ans;
    }
};