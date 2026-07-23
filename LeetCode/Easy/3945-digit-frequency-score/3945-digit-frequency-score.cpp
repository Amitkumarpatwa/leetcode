class Solution {
public:
    int digitFrequencyScore(int n) {
        int hash[10]={0};
        while(n){
            int digit=n%10;
            hash[digit]++;
            n=n/10;
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans+=i*hash[i];
        }
        return ans;
    }
};