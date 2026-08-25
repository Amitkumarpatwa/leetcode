class Solution {
public:
    // int gcd(int num1, int num2){
    //     if((num1%num2)==0){
    //     return num2;
    //     }
    //     int r=num1%num2;
    //     return gcd(num2,r);

    // }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();

        int first =nums[0];
        int last =nums[n-1];

        while(first!=last){
            if(first>last) first=first-last;
            else last=last-first;
        }
        
        return first;

    }
};