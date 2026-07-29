class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        for(int i : nums) sum+=i;

        int leftSum=0,rightSum=sum,index=0;

        for(int i : nums){
            rightSum-=i;

            if(rightSum==leftSum) return index;

            leftSum+=i;
            index++;
        }

        return -1;
    }
};