class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 1;
        sort(intervals.begin(), intervals.end());
        vector<int> newInterval;
        newInterval = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= newInterval[1]){
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            else{
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};