class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        int idx=0;
        int totalG=0;
        int tank=0;
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            totalG+=diff;
            tank+=diff;
            if(tank<0){
                idx=i+1;
                tank=0;
            }
        }
        return (totalG>=0)?idx:-1;
    }
};