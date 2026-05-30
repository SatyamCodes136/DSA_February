class Solution {
public:

    int nextEle(int n){
        int sum = 0;
        while(n > 0){
            int digit = n%10;
            sum += digit*digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1 && !s.count(n)){
            s.insert(n);
            n = nextEle(n);
        }
        return n == 1;
    }
};