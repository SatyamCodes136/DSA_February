class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n == 1) return stoi(tokens[0]);
        stack<string> st;
        int i = 0;
        int t3 = 0;
        while(i < n){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
              int t1 = stoi(st.top());
              st.pop();
              int t2 = stoi(st.top());
              st.pop();
              t3 = 0;
              if(tokens[i] == "+") t3 = t2+t1;
              else if(tokens[i] == "-") t3 = t2-t1;
              else if(tokens[i] == "*") t3 = t2*t1;
              else t3 = t2/t1;
              string s = to_string(t3);
              st.push(s);
              s = "";
            }
            else st.push(tokens[i]);
            i++;
        }
        return t3;
    }
};