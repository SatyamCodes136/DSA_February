class Solution {
public:

    vector<int> CalculatePreMax(vector<int>& height){
        vector<int> PreMax(height.size());
        PreMax[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            PreMax[i] = max(PreMax[i-1], height[i]);
        }
        return PreMax;
    }

    vector<int> CalculateSuffMax(vector<int>& height){
        int n = height.size();
        vector<int> SuffMax(n);
        SuffMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            SuffMax[i] = max(SuffMax[i+1], height[i]);
        }
        return SuffMax;
    }

    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        vector<int> PreMax = CalculatePreMax(height);
        vector<int> SuffMax = CalculateSuffMax(height);
        for(int i = 0; i < n; i++){
            if(height[i] < PreMax[i] && height[i] < SuffMax[i]){
                total += min(PreMax[i], SuffMax[i]) - height[i];
            }
        }
        return total;
    }
};