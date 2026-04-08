class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge(n2);
        stack<int> st;

        // Step 1: Compute NGE for nums2
        for(int i = n2 - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            
            st.push(nums2[i]);
        }

        // Step 2: Build answer for nums1 (without map)
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            int val = nums1[i];
            
            // find index in nums2
            int idx = -1;
            for(int j = 0; j < n2; j++) {
                if(nums2[j] == val) {
                    idx = j;
                    break;
                }
            }
            
            ans.push_back(nge[idx]);
        }

        return ans;
    }
};