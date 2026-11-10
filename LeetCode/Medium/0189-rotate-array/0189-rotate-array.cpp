class Solution {
public:
    void reversePart(int start,int end,vector<int>& nums){
        while(start<end){
            swap(nums[start++],nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        reversePart(0,n-k-1,nums);
        reversePart(n-k,n-1,nums);
        reversePart(0,n-1,nums);
    }
};