class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int proNum=1;
            int ans=num;
            while(num>0){
                int digit=num%10;
                proNum*=digit;
                num/=10;
            }

            if(proNum%t==0) return ans;
            ans++;
            num=ans;
        }
        return -1;
    }
};