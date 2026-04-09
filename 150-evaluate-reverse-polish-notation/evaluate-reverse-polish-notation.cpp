class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        while(i < tokens.size()){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
              int t1 = st.top();
              st.pop();
              int t2 = st.top();
              st.pop();
              if(tokens[i] == "+") st.push(t2+t1);
              else if(tokens[i] == "-") st.push(t2-t1);
              else if(tokens[i] == "*") st.push(t2*t1);
              else st.push(t2/t1);
            }
            else st.push(stoi(tokens[i]));
            i++;
        }
        return st.top();
    }
};