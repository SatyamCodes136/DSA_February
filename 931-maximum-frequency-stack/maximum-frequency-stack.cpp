class FreqStack {
private:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> st;
    int maxFreq = 0;

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int f = ++freq[val];
        maxFreq = max(maxFreq, f);
        st[f].push(val);
    }
    
    int pop() {
        int val = st[maxFreq].top();
        st[maxFreq].pop();
        freq[val]--;
        if(st[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */