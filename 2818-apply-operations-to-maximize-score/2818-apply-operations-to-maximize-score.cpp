#define ll long long int
class Solution {
    const int MOD = 1e9 + 7;
private:
    int findNumberOfUniquePrimeFactors(int x){
        set<int> s;
        for(int i = 2; i * i <= x; i++){
            while(x % i == 0){
                x /= i;
                s.insert(i);
            }
        }
        if(x > 1){
            s.insert(x);
        }
        return s.size();
    }
private:
    void FindScore(vector<int>& nums, vector<ll>& score){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            score[i] = findNumberOfUniquePrimeFactors(nums[i]);
        }
    }
private:
    void FindLeftIncreasing(vector<ll>& score, vector<ll>& leftIncreasing){
        int n = score.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && score[st.top()] < score[i]){
                st.pop();
            }
            if(st.empty()){
                leftIncreasing[i] = i + 1;
            }
            else{
                leftIncreasing[i] = i - st.top();
            }
            st.push(i);
        }
    }
private:
    void FindRightIncreasing(vector<ll>& score, vector<ll>& rightIncreasing){
        int n = score.size();
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && score[st.top()] <= score[i]){
                st.pop();
            }
            if(st.empty()){
                rightIncreasing[i] = n - i;
            }
            else{
                rightIncreasing[i] = st.top() - i ;
            }
            st.push(i);
        }
    }
private:
    int findPower(ll a, ll b){
        ll res = 1;
        a %= MOD;
        b %= MOD;
        while(b){
            if(b % 2){
                res = (res % MOD * a % MOD) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return res % MOD;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> score(n, 0);
        FindScore(nums, score);
        vector<ll> leftIncreasing(n, 1LL), rightIncreasing(n, 1LL);
        FindLeftIncreasing(score, leftIncreasing);
        FindRightIncreasing(score, rightIncreasing);
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        ll ans = 1;
        while(k > 0 && !pq.empty()){
            int index = pq.top().second;
            int num = pq.top().first;
            pq.pop();
            int cntSubarrays = leftIncreasing[index] * rightIncreasing[index];
            cntSubarrays = min(cntSubarrays, k);
            k -= cntSubarrays;
            ll current = findPower(num, cntSubarrays);
            ans = ((ans % MOD) * (current % MOD)) % MOD;
        }
        return ans;
    }
};