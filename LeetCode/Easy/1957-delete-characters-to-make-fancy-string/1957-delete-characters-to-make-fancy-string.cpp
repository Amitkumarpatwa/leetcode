class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prev=s[0];
        int count=1;
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(prev==s[i]){
                count++;
                prev=s[i];
            }
            else{
                count=1;
                prev=s[i];
            }
            if(count<3){
                ans+=s[i];
                prev=s[i];
            }
        }
        return ans;
    }
};