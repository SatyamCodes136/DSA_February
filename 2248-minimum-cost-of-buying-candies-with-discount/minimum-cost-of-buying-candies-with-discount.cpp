class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        long long c = 0;
        sort(cost.rbegin(), cost.rend());
        for(int i = 0; i < n; i++){
            if(i%3 != 2) c += cost[i];
        }
        return c;
    }
};