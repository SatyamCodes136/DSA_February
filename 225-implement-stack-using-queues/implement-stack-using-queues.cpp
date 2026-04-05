class MyStack {
private:
    queue<int> Q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = Q.size();
        Q.push(x);
        for(int i = 0; i < s; i++){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop() {
        int val = Q.front();
       Q.pop(); 
       return val;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */