class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        long long maxi = INT_MIN;
        int i = 0;
        int j = n-1;
        while(i < j){
            long long area = min(height[i], height[j])*(j-i);
            maxi = max(maxi,area);
            if(height[i] > height[j]) j--;
            else i++;
        }
        return maxi;
    }
};