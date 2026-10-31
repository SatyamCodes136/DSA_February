class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int low = 1;
        int high = x-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long m = (long long)mid;
            long long y = (long long)x;
            if(m*m == y) return mid;
            else if(m*m > x) high = mid-1;
            else low = mid+1;
        }
        return low-1;
    }
};