class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, sum = 1;
        while(i < n){
            // case1: flat slope
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            // case2: increasing slope
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            // case 3: decreasing slope
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak) sum += down - peak;
        }
        return sum;
    } 
};