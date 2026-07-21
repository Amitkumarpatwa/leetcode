class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int len=0, zero=0;

        while(r<n){
            if(nums[r]==0) zero++;

            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }

            len=max(r-l+1,len);
            r++;
        }

        return len;
    }
};