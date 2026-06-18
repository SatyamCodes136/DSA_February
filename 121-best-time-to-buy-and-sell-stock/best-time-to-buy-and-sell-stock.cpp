class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = INT_MAX;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] < mini) mini = prices[i];
            maxi = max(maxi, prices[i+1]-mini);
        }
        return maxi;
    }
};