class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0;
        
        while(arr[i][m - 1] < k)
        {  
            i++;
            if(i == n)break;
        }
        if(i >= n){
            return false;
        }
        int low = 0;
        int high = m;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(arr[i][mid] == k){
                    return true;
            }
            else if (arr[i][mid] < k){
                low = mid + 1;
            }
            else{
                high = mid;
                }
            }
            return false;
        
    }
};