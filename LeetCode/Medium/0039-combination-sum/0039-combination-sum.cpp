class Solution {
public:
    void combination(vector<vector<int>>& ans,vector<int>&temp,vector<int>&candidates,int target,int idx){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target<0 || idx==candidates.size()) return;

        //recursion magic
        temp.push_back(candidates[idx]);
        combination(ans,temp,candidates,target-candidates[idx],idx);
        temp.pop_back();
        combination(ans,temp,candidates,target,idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans,temp,candidates,target,0);
        return ans;
    }
};