#define ll long long int
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<ll>> dp(goal + 1, vector<ll>(n + 1, 0));
        dp[0][0] = 1;
        for(int songs = 1; songs <= goal; songs++){
            for(int unique = 1; unique <= min(songs, n); unique++){
                // taking new song, (n - (unique - 1) ways to choose new song)
                dp[songs][unique] = ((dp[songs - 1][unique - 1] % MOD) * (n - unique + 1) % MOD) % MOD;
                // taking prev song which is not unique and unique songs are greater than k
                if(unique > k){
                    dp[songs][unique] =  (dp[songs][unique] % MOD + dp[songs - 1][unique] * (unique - k)) % MOD;
                    // (unique - k) ways to choose the prev song
                }
            }
        }
        return dp[goal][n];
    }
};