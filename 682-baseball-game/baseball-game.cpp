class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int sum = 0;
        stack<int> s;
        for(int i = 0; i < n; i++){
            if(operations[i] == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                int c = a+b;
                s.push(a);
                s.push(c);
            }
            else if(operations[i] == "D"){
                int a = s.top();
                int c = a*2;
                s.push(c);
            }
            else if(operations[i] == "C"){
                s.pop();
            }
            else{
                int c = stoi(operations[i]);
                s.push(c);
            }
        }
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};