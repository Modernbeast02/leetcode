class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> findDistance(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int newx = x + dx[dir];
                int newy = y + dy[dir];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    if(distance[x][y] + 1 < distance[newx][newy]){
                        distance[newx][newy] = distance[x][y] + 1;
                        q.push({newx, newy});
                    }
                }
            }
        }
        return distance;
    }
private:
    bool checkIfPossible(vector<vector<int>>& grid, int mid){
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] < mid || grid[n - 1][m - 1] < mid){
            return false;
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x == n - 1 && y == m - 1){
                return true;
            }
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int newx = x + dx[dir];
                int newy = y + dy[dir];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && grid[newx][newy] >= mid){
                    q.push({newx, newy});
                    visited[newx][newy] = 1;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance = findDistance(grid);
        int ans = -1;
        int low = 0, high = 1e6;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(checkIfPossible(distance, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};