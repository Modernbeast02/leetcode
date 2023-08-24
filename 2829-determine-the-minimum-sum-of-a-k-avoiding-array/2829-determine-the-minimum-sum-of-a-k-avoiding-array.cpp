class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        if(k / 2 >= n){
            return (n * (n + 1)) / 2;
        }
        for(int i = 1; i <= k / 2; i++){
            ans += i;
        }
        n -= k / 2;
        for(int i = k; n > 0; i++){
            ans += i;
            n--;
        }
        return ans;
    }
};