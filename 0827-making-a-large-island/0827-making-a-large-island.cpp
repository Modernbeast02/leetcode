class DSU {
public:
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
        // path compression -> (log n)
        // path compression and size -> O(4 x alpha)
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m + 1);
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int dir = 0; dir < 4; dir++){
                        int x = i + dx[dir];
                        int y = j + dy[dir];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                            dsu.unionSize(i * m + j, x * m + y);
                        }
                    }
                }
            }
        } 
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dsu.size[i * m + j]);
                // changing it to 1
                if(grid[i][j] == 0){
                    set<int> parents;
                    for(int dir = 0; dir < 4; dir++){
                        int x = i + dx[dir];
                        int y = j + dy[dir];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                           parents.insert(dsu.findPar(x * m + y));
                        }
                    }
                    int cnt = 0;
                    for(auto nodes : parents){
                        cnt += dsu.size[nodes];
                    }
                    cnt++;
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;  
    }
};