class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        n = nums.size();
        map<int, int> ans, prevIndex;
        for(int i = 0; i < n; i++){
            if(prevIndex.find(nums[i]) != prevIndex.end()){
                ans[nums[i]] = max(ans[nums[i]], (i - prevIndex[nums[i]]) / 2);
            }
            prevIndex[nums[i]] = i;
        }
        int res = 1e9;
        for(auto it : ans){
            res = min(res, it.second);
        }
        return res;
    }
};