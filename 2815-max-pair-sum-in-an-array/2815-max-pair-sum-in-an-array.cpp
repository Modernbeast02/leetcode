class Solution {
private:
    int findMaxNumber(int x){
        int maxi = 0;
        while(x){
            maxi = max(maxi, x % 10);
            x /= 10;
        }
        return maxi;
    }
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            int x = findMaxNumber(nums[i]);
            mpp[x].push_back(nums[i]);
        }
        int ans = -1;
        for(auto &it : mpp){
            vector<int> current = it.second;
            sort(current.begin(), current.end());
            if(current.size() > 1){
                ans = max(ans, current.back() + current[current.size() - 2]);
            }
        }
        return ans;
    }
};