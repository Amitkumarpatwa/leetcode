class Solution {
public:
    int rev(int num){
        int n=0;
        while(num>0){
            int rem=num%10;
            n=n*10+rem;
            num/=10;
        }
        return n;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            st.insert(rev(nums[i]));
        }
        return st.size();
    }
};