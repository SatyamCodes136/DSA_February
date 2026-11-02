class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int idx = -1;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1]){
                continue;
            }
            else if(arr[i] < arr[i-1]){
                idx = i;
                break;
            }
            else if(arr[i] == arr[i-1]) return false;
        }
        if(idx == 1 || idx == -1) return false;
        while(idx >= 0 && idx < n-1){
            if(arr[idx] <= arr[idx+1]) return false;
            idx++;
        }
        return true;
    }
};