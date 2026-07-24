class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());

        int minDif=INT_MAX;

        for(int i=0;i<arr.size()-1;i++){
            int diff=arr[i+1]-arr[i];

            if(diff<minDif){
                minDif=diff;
                ans.clear();

                ans.push_back({arr[i],arr[i+1]});
            }else if(diff==minDif) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};