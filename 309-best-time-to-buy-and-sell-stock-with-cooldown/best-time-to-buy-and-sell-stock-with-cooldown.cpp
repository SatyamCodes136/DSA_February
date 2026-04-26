class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        int hold = -prices[0];  
        int sold = 0;           
        int rest = 0;           

        for(int i = 1; i < n; i++) {
            int prev_sold = sold;

            sold = hold + prices[i];          // sell today
            hold = max(hold, rest - prices[i]); // buy or keep holding
            rest = max(rest, prev_sold);      // cooldown or keep resting
        }

        return max(sold, rest);
    }
};