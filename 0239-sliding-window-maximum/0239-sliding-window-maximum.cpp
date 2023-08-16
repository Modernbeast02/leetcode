class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // we can solve this problem in 3 ways
        // 1st - using multiset
        // 2nd - using prioroty queue
        // 3rd - using deque
        vector<int> result;
        deque<int> deq;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!deq.empty() && i-k >= 0 &&  deq.front() == nums[i-k]) 
                deq.pop_front();
            
            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();
            
            deq.push_back(nums[i]);
            
            if (i >= k-1)
                result.push_back(deq.front());
        }
        
        return result;
    }
};