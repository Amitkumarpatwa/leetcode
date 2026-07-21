class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int n=fruits.size();
     int l=0,r=0,len=0;
     map<int,int>mpp;

     while(r<n){
        mpp[fruits[r]]++;

        //if sized exceed
        if(mpp.size()>2){
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
        }
        
        len=max(len,r-l+1);
        r++;
     }   
    return len;
    }
};