class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int element = st.top(); st.pop();
                int nse = i; // next smaller element
                int pse = st.empty() ? -1 : st.top(); // previous smaller element
                maxArea = max(maxArea, (nse - pse -1)*heights[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1)*heights[element]);
        }
        return maxArea;
    }
};