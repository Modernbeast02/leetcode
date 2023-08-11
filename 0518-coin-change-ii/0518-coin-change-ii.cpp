class Solution {
private:
    int dp1[305][5005];
    int FindAns(int index, int amount, vector<int> & coins){
        if(amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp1[index][amount] != -1){
            return dp1[index][amount];
        }
        if(index == coins.size()){
            return 0;
        }
        return dp1[index][amount] = FindAns(index + 1, amount, coins) + FindAns(index, amount - coins[index], coins);

    }
public:
    int change(int amount, vector<int>& coins) {
        // memset(dp, -1, sizeof(dp));
        // return FindAns(0, amount, coins);
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int index = n - 1; index >= 0; index--){
            for(int j = 0; j <= amount; j++){
                dp[index][j] = dp[index + 1][j];
                if(j >= coins[index]){
                    dp[index][j] += dp[index][j - coins[index]];
                }
            }
        }
        return dp[0][amount];
    }
};