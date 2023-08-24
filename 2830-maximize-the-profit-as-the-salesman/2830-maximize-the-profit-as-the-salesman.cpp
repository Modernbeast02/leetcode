class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        int maxi = -1;
        for(int i = 0; i < m; i++){
            maxi = max(maxi, offers[i][1]);
        }
        vector<int> maxAns(maxi + 1, 0);
        sort(offers.begin(), offers.end(), [](vector<int> &a, vector<int>& b){
            return a[1] < b[1];
        });
        int j = 0;
        for(int i = 0; i < maxi + 1; i++){
            if(i > 0){
                maxAns[i] = maxAns[i - 1];
            }
            while(j < m && offers[j][1] == i){
                int prev = offers[j][0] - 1;
                if(prev < 0){
                    prev = 0;
                }
                else{
                    prev = maxAns[prev];
                }
                maxAns[i] = max(maxAns[i], prev + offers[j][2]);
                j++;
            }
        }
        return *max_element(maxAns.begin(), maxAns.end());
    }
};