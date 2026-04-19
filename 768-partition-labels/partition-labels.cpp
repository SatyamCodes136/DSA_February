class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>freq(26,-1);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
        }
        vector<int>res;
        int start=0;
        int e=0;
        for(int i=0;i<n;i++){
           e=max(e,freq[s[i]-'a']);
           if(i==e){
                res.push_back(e-start+1);
                start=i+1;
           }
        }
        return res;
    }
};