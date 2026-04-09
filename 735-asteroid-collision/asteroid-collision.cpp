class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        int i = 1;
        stack<int> st;
        st.push(arr[0]);
        while(i < n){
                bool alive = true;
                while(alive && !st.empty() && st.top() > 0 && arr[i] < 0){
                    if(abs(arr[i]) > st.top()) st.pop();
                    else if(abs(arr[i]) == st.top()){
                        st.pop();
                        alive = false;
                    }
                    else alive = false;
                }
                if(alive) st.push(arr[i]);
            i++;
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};