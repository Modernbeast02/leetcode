class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> s;
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            if(i >= x){
                s.insert(nums[i - x]);
            }
            if(s.size() > 0){
                auto num = s.lower_bound(nums[i]);
                if(num != s.end()){
                    ans = min(ans, abs(nums[i] - *num));
                }
                if(num != s.begin()){
                    num--;
                    ans = min(ans, abs(nums[i] - *num));
                }
            }
        }
        return ans;
    }
};